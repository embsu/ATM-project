#include "engine.h"

engine::engine(){
    /* TO DO:
 * Tuplakyselyn jälkeen toiminta
 * Lisää tapahtuma <--- idDebitti selvitetty. Seuraavaksi tapahtumien luonti!!
 * Tapahtumassa liikkuminen 5 eteen 5 taakse
 */
}

//Login token
void engine::loginAccess(QString kortti, QString pin){
    kortinnumero = kortti;
    QJsonObject jsonObj;
    jsonObj.insert("kortin_numero", kortti);
    jsonObj.insert("PIN", pin);
    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    loginManager = new QNetworkAccessManager(this);

    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpRequestSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void engine::httpRequestSlot(QNetworkReply *replyhttp){
    response_data=replyhttp->readAll();

    if (QString::compare(response_data,"-4078") == 0 || response_data.length() == 0) {
        emit httpResponseReady(false, false, ""); //Kirjautumistiedot, Serverin status, Kortin tyyppi
    } else {
        if (response_data != "false") {
            token = "Bearer "+response_data;
            tilityyppi(kortinnumero); //FUNKTIO
            while (tilintyyppi == "") { //Odotetaan, että saadaan arvo päivitettyä saldofunktiosta.
                qApp->processEvents();
            }
            emit httpResponseReady(true, true, tilintyyppi);
        } else {
            emit httpResponseReady(false, true, "");
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}
void engine::tilityyppi(QString kortinnumero){

    QString url = "http://localhost:3000/kortti/"+kortinnumero;
    QNetworkRequest request ((url));
    request.setRawHeader(QByteArray("Authorization"), (token));
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(tiliTyyppiRequestSlot(QNetworkReply*)));
    reply = loginManager->get(request);
}
void engine::tiliTyyppiRequestSlot(QNetworkReply* reply) {

    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString data;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        data+=json_obj["Tyyppi"].toString();
    }
    tilintyyppi = data;
    reply->deleteLater();
    loginManager->deleteLater();
}

//Menu arvot
void engine::menu(QString toiminto){

    QString url = "http://localhost:3000/"+toiminto;
    QNetworkRequest request ((url));
    request.setRawHeader(QByteArray("Authorization"), (token));
    TableManager = new QNetworkAccessManager(this);
    connect(TableManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(menuRequestSlot(QNetworkReply*)));
    reply = TableManager->get(request);


}
void engine::menuRequestSlot(QNetworkReply *reply) {

    response_data = reply->readAll();
    QString data = response_data;
    emit sendMenuToInterface(data);

    reply->deleteLater();
    TableManager->deleteLater();
}

void engine::saldo(QString kortinnumero){

    if (tilintyyppi == "debit") {
        QString url = "http://localhost:3000/debit/"+kortinnumero;
        QNetworkRequest request ((url));
        request.setRawHeader(QByteArray("Authorization"), (token));
        saldoManager = new QNetworkAccessManager(this);
        connect(saldoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(saldoRequestSlot(QNetworkReply*)));
        reply = saldoManager->get(request);

    } else if (tilintyyppi == "credit"){
        QString url = "http://localhost:3000/credit/"+kortinnumero;
        QNetworkRequest request ((url));
        request.setRawHeader(QByteArray("Authorization"), (token));
        saldoManager = new QNetworkAccessManager(this);
        connect(saldoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(saldoRequestSlot(QNetworkReply*)));
        reply = saldoManager->get(request);
    }
}
void engine::saldoRequestSlot(QNetworkReply *reply) {
    response_data = reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString data;

    if(tilintyyppi == "debit") {
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            data+=QString::number(json_obj["saldo"].toDouble());
            idDebit=QString::number(json_obj["idDebit"].toInt());
        }
    } else if (tilintyyppi == "credit"){
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            data+=QString::number(json_obj["luottosaldo"].toDouble());
            idCredit=QString::number(json_obj["idCredit"].toInt());
        }
    }
    saldoMaara = data;
    if(saldoPaivitys != "paivitys") {
        emit sendSaldoToInterface(data);
    } else {
        saldoPaivitys = "pyynto";
    }
    reply->deleteLater();
    saldoManager->deleteLater();
}
void engine::otto(QString maara, QString kortti){

    //Päivitetään saldo arvo nopee
    saldoPaivitys = "paivitys";
    saldo(kortti); //Tyhjä arvo koske me alustetaankin se ihan alussa.
    while (saldoMaara == "") { //Odotetaan, että saadaan arvo päivitettyä saldofunktiosta.
        qApp->processEvents();
    }
    nostoMaara = maara;
    nostoTyyppi = "nosto";
    //kortinnumero = kortti;
    double nostettavaa = nostoMaara.toDouble();
    double tilinSaldo = saldoMaara.toDouble();
    if (tilintyyppi == "debit") {
        if(nostettavaa > tilinSaldo) {
            emit sendOttoToInterface("Virheellinen määrä");
        } else {
            double vahennys = tilinSaldo - nostettavaa;
            paivitettySaldo = QString::number(vahennys);

            QJsonObject jsonObj;
            jsonObj.insert("Saldo",paivitettySaldo);

            QString url="http://localhost:3000/debit/"+kortinnumero;
            QNetworkRequest request((url));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            request.setRawHeader(QByteArray("Authorization"),(token));

            ottoPutManager = new QNetworkAccessManager(this);
            connect(ottoPutManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(ottoRequestSlot(QNetworkReply*)));
            reply = ottoPutManager->put(request, QJsonDocument(jsonObj).toJson());
        }
    } else if (tilintyyppi == "credit") {
        if(nostettavaa > tilinSaldo) {
            emit sendOttoToInterface("Virheellinen määrä");
        } else {
            double vahennys = tilinSaldo - nostettavaa;
            paivitettySaldo = QString::number(vahennys);

            QJsonObject jsonObj;
            jsonObj.insert("Luottosaldo",paivitettySaldo);

            QString url="http://localhost:3000/credit/"+kortinnumero;
            QNetworkRequest request((url));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            request.setRawHeader(QByteArray("Authorization"),(token));

            ottoPutManager = new QNetworkAccessManager(this);
            connect(ottoPutManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(ottoRequestSlot(QNetworkReply*)));
            reply = ottoPutManager->put(request, QJsonDocument(jsonObj).toJson());
        }
    }
}

void engine::ottoRequestSlot(QNetworkReply *reply) {
    response_data=reply->readAll();
    lisaaTapahtuma();
    while (lisattiinTapahtuma == "") { //Odotetaan, että saadaan lisättyä tilitapahtuma
        qApp->processEvents();
    }
    emit sendOttoToInterface(paivitettySaldo);
    reply->deleteLater();
    ottoPutManager->deleteLater();
}
void engine::tapahtumat(QString kortinnumero) {
    qDebug()<<"Tullanko enginen tapahtumiin?";
    if(tilintyyppi == "credit") {
        qDebug()<<"Tultiinko credittiin?";
        QString url = "http://localhost:3000/creditTapahtumat/"+kortinnumero;
        QNetworkRequest request ((url));
        request.setRawHeader(QByteArray("Authorization"), (token));
        tapahtumatManager = new QNetworkAccessManager(this);
        connect(tapahtumatManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(tapahtumatRequestSlot(QNetworkReply*)));
        reply = tapahtumatManager->get(request);

    } else if (tilintyyppi == "debit") {
        qDebug()<<"Tullaanko debittiin?";
        QString url = "http://localhost:3000/debitTapahtumat/"+kortinnumero;
        QNetworkRequest request ((url));
        request.setRawHeader(QByteArray("Authorization"), (token));
        tapahtumatManager = new QNetworkAccessManager(this);
        connect(tapahtumatManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(tapahtumatRequestSlot(QNetworkReply*)));
        reply = tapahtumatManager->get(request);
    }
}

void engine::tapahtumatRequestSlot(QNetworkReply* reply) {
    qDebug()<<"Tullaanko ollenkaan tapahtuma requestiin?";
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString data;

    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        data+=QString::number(json_obj["Maara"].toDouble())
                +" "+json_obj["Tyyppi"].toString()
                +" "+json_obj["Paivamaara"].toString()+"\r\n";
    qDebug()<<"Tullaanko tapahtumarequest slottiin lähettäämään?";
    emit sendTapahtumatToInterface(data);
        reply->deleteLater();
        tapahtumatManager->deleteLater();
    }
}

void engine::lisaaTapahtuma(){
    //Alustetaan aika
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString(Qt::ISODate);

    if (tilintyyppi =="debit") {
        QJsonObject jsonObj;
        jsonObj.insert("Maara",nostoMaara);
        jsonObj.insert("Tyyppi",nostoTyyppi);
        jsonObj.insert("Paivamaara",currentDateTimeString);
        jsonObj.insert("idDebit",idDebit);

        QString site_url="http://localhost:3000/debitTapahtumat";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(token));
        lisaatapahtumaManager = new QNetworkAccessManager(this);
        connect(lisaatapahtumaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(lisaatapahtumaRequestSlot(QNetworkReply*)));
        reply = lisaatapahtumaManager->post(request, QJsonDocument(jsonObj).toJson());

    } else if (tilintyyppi == "credit") {
        QJsonObject jsonObj;
        jsonObj.insert("Maara",nostoMaara);
        jsonObj.insert("Tyyppi",nostoTyyppi);
        jsonObj.insert("Paivamaara",currentDateTimeString);
        jsonObj.insert("idCredit",idCredit);

        QString site_url="http://localhost:3000/creditTapahtumat";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(token));
        lisaatapahtumaManager = new QNetworkAccessManager(this);
        connect(lisaatapahtumaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(lisaatapahtumaRequestSlot(QNetworkReply*)));
        reply = lisaatapahtumaManager->post(request, QJsonDocument(jsonObj).toJson());
    }
}

void engine::lisaatapahtumaRequestSlot(QNetworkReply *reply){
    response_data=reply->readAll();
    lisattiinTapahtuma = "Lisättiin"; //Tapahtuman lisäys onnistui
    reply->deleteLater();
    lisaatapahtumaManager->deleteLater();
}
//TUPLAKORTIN ALUSTUS!
void engine::tuplakorttiAlustus(QString tilityyppi){
    tilintyyppi = tilityyppi;
    qDebug () << "Engineen alustettu tilityyppi: " + tilintyyppi;
}







