#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
class engine: public QObject
{
    Q_OBJECT
public:
    engine();

private slots:
    //Login
    void httpRequestSlot(QNetworkReply* reply);
    void loginAccess(QString, QString);
    //Menu
    void menu(QString);
    void menuRequestSlot(QNetworkReply* reply);
    //Tilityyppi
    void tilityyppi(QString);
    void tiliTyyppiRequestSlot(QNetworkReply* reply);
    //saldo
    void saldo(QString);
    void saldoRequestSlot(QNetworkReply* reply);
    //otto
    void otto (QString, QString);
    void ottoRequestSlot(QNetworkReply* reply);
    //tapahtumat
    void tapahtumat(QString);
    void tapahtumatRequestSlot(QNetworkReply* reply);
    void lisaaTapahtuma();
    void lisaatapahtumaRequestSlot(QNetworkReply* reply);


signals:
    void httpResponseReady(bool, bool, QString);//Tunnukset, serveristatus, kortin tyyppi
    void sendMenuToInterface(QString);
    void sendSaldoToInterface(QString);
    void sendOttoToInterface(QString);
    void sendTapahtumatToInterface(QString);
private:
    friend class DLLRestAPI;

    //Serverin alustus
    QNetworkReply *reply;
    QByteArray response_data;

    //Login
    QNetworkAccessManager *loginManager;
    QByteArray token;
    QString httpResponse;
    QString tilintyyppi;

    //Menu
    QNetworkAccessManager *TableManager;
    QByteArray tauluilleToken;
    void tuplakorttiAlustus(QString);
    //Saldo
    QNetworkAccessManager *saldoManager;
    QString tilinSaldo;
    //Otto
    QNetworkAccessManager *ottoManager;
    QNetworkAccessManager *ottoPutManager;
    QString nostoMaara;
    QString kortinnumero;
    QString saldoMaara;
    QString paivitettySaldo;
    QString saldoPaivitys;
    //Tapahtumat
    QNetworkAccessManager *tapahtumatManager;
    QNetworkAccessManager *lisaatapahtumaManager;
    QString idDebit;
    QString idCredit;
    QString nostoTyyppi;
    QString lisattiinTapahtuma;


};

#endif // ENGINE_H
