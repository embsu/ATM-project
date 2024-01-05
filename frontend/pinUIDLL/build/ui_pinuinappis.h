/********************************************************************************
** Form generated from reading UI file 'pinuinappis.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINUINAPPIS_H
#define UI_PINUINAPPIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pinUInappis
{
public:
    QLineEdit *PinLineEdit;
    QFrame *PinFrame;
    QGridLayout *gridLayout;
    QPushButton *B4;
    QPushButton *B0;
    QPushButton *B1;
    QPushButton *B9;
    QPushButton *B3;
    QPushButton *BEnter;
    QPushButton *B7;
    QPushButton *B8;
    QPushButton *B5;
    QPushButton *BCancel;
    QPushButton *B2;
    QPushButton *B6;
    QLabel *label;
    QLabel *label_2;
    QLabel *pirkkal;
    QFrame *frame;

    void setupUi(QDialog *pinUInappis)
    {
        if (pinUInappis->objectName().isEmpty())
            pinUInappis->setObjectName("pinUInappis");
        pinUInappis->resize(716, 580);
        pinUInappis->setMouseTracking(false);
        pinUInappis->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(173, 173, 173, 255), stop:0.478873 rgba(84, 102, 109, 255), stop:0.915493 rgba(72, 72, 72, 255));\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(75, 75, 75, 255), stop:0.57277 rgba(152, 152, 152, 255), stop:1 rgba(161, 161, 161, 255));\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 139, 139, 255), stop:0.525822 rgba(191, 191, 191, 255), stop:1 rgba(161, 161, 161, 255));\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 139, 139, 255), stop:0.525822 rgba(226, 226, 226, 255), stop:1 rgba(161, 161, 161, 255));\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(132, 132, 132, 255), stop:0.525822 rgba(185, 185, 185, 255), stop:1 rgba(148, 148, 148, 255));\n"
"\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb"
                        "a(51, 51, 51, 255), stop:				0.525822 rgba(95, 95, 95, 255), stop:1 rgba(58, 58, 58, 255));\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QFrame {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.431818, x2:1, y2:0.409364, stop:0.217877 rgba(43, 43, 43, 255), stop:0.50838 rgba(64, 64, 64, 255), stop:0.938547 rgba(37, 37, 37, 255));\n"
"\n"
"border: 4px ridge #383838; \n"
"border-radius: 10px;\n"
"\n"
"\n"
"}\n"
"\n"
"QFrame#frame {\n"
"background-color: rgb(75, 75, 75);\n"
"	\n"
"	border: 2px inset #4a8390;\n"
"	border-radius: 20px;\n"
"}\n"
"QLabel {\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"	\n"
"	font: 20pt bold \"Titillium Web\"; \n"
"\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0.414773, x2:1, y2:0.409364, stop:0.122905 rgba(18, 18, 18, 255), stop:0.513966 rgba(64, 64, 64, 255), stop:0.949721 rgba(4, 4, 4, 255));\n"
"	color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0.497653, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(177, 177, 177, 255));\n"
""
                        "	color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0.488, y2:0, stop:0 rgba(243, 243, 243, 255), stop:0.85446 rgba(166, 166, 166, 255));\n"
"\n"
"	background-color: qlineargradient(spread:reflect, x1:0.245, y1:0.137636, x2:1, y2:0.153, stop:0.0893855 rgba(84, 83, 83, 255), stop:0.597765 rgba(148, 148, 148, 255), stop:0.927374 rgba(180, 191, 191, 255)); \n"
"\n"
"	background-color: qlineargradient(spread:pad, x1:0.099, y1:0, x2:0.864, y2:0.0170455, stop:0 rgba(25, 25, 25, 255), stop:1 rgba(114, 114, 114, 255));\n"
"	background-color: qlineargradient(spread:pad, x1:0.156, y1:0, x2:1, y2:0.045, stop:0 rgba(50, 50, 50, 255), stop:1 rgba(144, 144, 144, 255));\n"
"\n"
"	border: 3px groove #6f6f6f;\n"
"	border-radius: 5px;\n"
"	padding: 3px;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0.971682, x2:1, y2:0.989045, stop:0.217877 rgba(87, 87, 87, 255), stop:0.625698 rgba(219, 219, 219, 255), stop:0.905028 rgba(196, 196, 196, 255));\n"
"	color: qlineargradie"
                        "nt(spread:reflect, x1:0.005, y1:0, x2:0.488, y2:0, stop:0 rgba(186, 186, 186, 255), stop:0.812207 rgba(106, 106, 106, 255));\n"
"	color: qlineargradient(spread:reflect, x1:0.005, y1:0, x2:0.488, y2:0, stop:0 rgba(95, 95, 95, 255), stop:0.812207 rgba(28, 28, 28, 255));\n"
"   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.414773, x2:1, y2:0.409364, stop:0.268156 rgba(30, 30, 30, 255), stop:			  0.636872 rgba(55, 55, 55, 255), stop:1 rgba(136, 136, 136, 255));\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0.414773, x2:1, y2:0.409364, stop:0.122905 rgba(144, 144, 144, 255), stop:0.513966 rgba(255, 255, 255, 255), stop:0.949721 rgba(132, 132, 132, 255));\n"
"\n"
"border: 3px groove #393939;\n"
"}\n"
"\n"
"QPushButton#BCancel {\n"
"\n"
"	color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0.55, y2:0, stop:0 rgba(145, 45, 47, 255), stop:1 rgba(163, 68, 74, 255));\n"
"	\n"
"}\n"
"\n"
"QPushButton#BCancel:hover {\n"
"	background-color: qlineargradient(spread:re"
                        "flect, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(144, 35, 35, 255), stop:0.418994 rgba(255, 170, 141, 255), stop:0.854749 rgba(200, 64, 64, 255));\n"
"}\n"
"\n"
"QPushButton#BCancel:pressed {\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0, stop:0.0111732 rgba(62, 18, 18, 255), stop:0.49162 rgba(153, 83, 106, 255), stop:0.832402 rgba(107, 25, 25, 255));\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0.437, x2:1, y2:0.472, stop:0.363128 rgba(191, 143, 143, 255), stop:1 rgba(251, 216, 216, 255));\n"
"\n"
"border: 3px groove #763839;\n"
"}\n"
"QPushButton#BEnter{\n"
" \n"
"	color: qlineargradient(spread:pad, x1:0, y1:0.391545, x2:1, y2:0.392, stop:0.223464 rgba(51, 182, 97, 255), stop:1 rgba(53, 251, 122, 255));\n"
"\n"
"}\n"
"\n"
"QPushButton#BEnter:hover {\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0, stop:0.0111732 rgba(66, 144, 35, 255), stop:0.418994 rgba(159, 255, 184, 255), stop:0.832402 rgba(63, 203, 76, 255));\n"
"	color: qlineargradient(spread:p"
                        "ad, x1:0, y1:0.391545, x2:1, y2:0.392, stop:0.223464 rgba(28, 100, 53, 255), stop:1 rgba(81, 159, 108, 255));\n"
" \n"
"}\n"
"QPushButton#BEnter:pressed {\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0, stop:0.0111732 rgba(28, 61, 15, 255), stop:0.418994 rgba(98, 148, 112, 255), stop:0.832402 rgba(24, 78, 29, 255));\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0.437, x2:1, y2:0.472, stop:0.363128 rgba(98, 177, 119, 255), stop:1 rgba(167, 241, 162, 255));\n"
"\n"
"border: 3px groove #1ea154;\n"
"}\n"
"\n"
"QLabel {	\n"
"	\n"
" 	color: #dadada;\n"
"	font: 290 16pt \"Microsoft YaHei Light\";\n"
"\n"
"}\n"
"QLabel#label_2 {	\n"
"	\n"
"	color: rgb(112, 22, 24);\n"
"	font: 290 16pt \"Microsoft YaHei Light\";\n"
"}\n"
"\n"
"QLabel#pirkkal {	\n"
"	color: #dadada;\n"
"	font: 350 10pt \"Leelawadee UI Semilight\";\n"
"	qproperty-geometry:rect(610 550 101 35);\n"
"}\n"
"\n"
"\n"
"QLineEdit {	\n"
"	\n"
"font: 290 16pt \"Microsoft YaHei Light\";\n"
"	color: #b1b1b1;\n"
"	border: 3px ridge "
                        "#383838;\n"
"\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.431818, x2:1, y2:0.409364, stop:0.217877 rgba(43, 43, 43, 255), stop:0.50838 rgba(64, 64, 64, 255), stop:0.938547 rgba(37, 37, 37, 255));\n"
"	border-radius:8px;\n"
"}\n"
"\n"
"\n"
""));
        PinLineEdit = new QLineEdit(pinUInappis);
        PinLineEdit->setObjectName("PinLineEdit");
        PinLineEdit->setGeometry(QRect(290, 420, 131, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei Light")});
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        PinLineEdit->setFont(font);
        PinLineEdit->setCursor(QCursor(Qt::IBeamCursor));
        PinLineEdit->setFocusPolicy(Qt::NoFocus);
        PinLineEdit->setEchoMode(QLineEdit::Normal);
        PinLineEdit->setAlignment(Qt::AlignCenter);
        PinFrame = new QFrame(pinUInappis);
        PinFrame->setObjectName("PinFrame");
        PinFrame->setGeometry(QRect(270, 190, 171, 226));
        PinFrame->setFrameShape(QFrame::StyledPanel);
        PinFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(PinFrame);
        gridLayout->setObjectName("gridLayout");
        B4 = new QPushButton(PinFrame);
        B4->setObjectName("B4");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("13 Titillium Web")});
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        B4->setFont(font1);

        gridLayout->addWidget(B4, 1, 0, 1, 1);

        B0 = new QPushButton(PinFrame);
        B0->setObjectName("B0");
        B0->setFont(font1);

        gridLayout->addWidget(B0, 3, 1, 1, 1);

        B1 = new QPushButton(PinFrame);
        B1->setObjectName("B1");
        B1->setFont(font1);

        gridLayout->addWidget(B1, 0, 0, 1, 1);

        B9 = new QPushButton(PinFrame);
        B9->setObjectName("B9");
        B9->setFont(font1);

        gridLayout->addWidget(B9, 2, 2, 1, 1);

        B3 = new QPushButton(PinFrame);
        B3->setObjectName("B3");
        B3->setFont(font1);

        gridLayout->addWidget(B3, 0, 2, 1, 1);

        BEnter = new QPushButton(PinFrame);
        BEnter->setObjectName("BEnter");
        BEnter->setFont(font1);

        gridLayout->addWidget(BEnter, 3, 2, 1, 1);

        B7 = new QPushButton(PinFrame);
        B7->setObjectName("B7");
        B7->setFont(font1);

        gridLayout->addWidget(B7, 2, 0, 1, 1);

        B8 = new QPushButton(PinFrame);
        B8->setObjectName("B8");
        B8->setFont(font1);

        gridLayout->addWidget(B8, 2, 1, 1, 1);

        B5 = new QPushButton(PinFrame);
        B5->setObjectName("B5");
        B5->setFont(font1);

        gridLayout->addWidget(B5, 1, 1, 1, 1);

        BCancel = new QPushButton(PinFrame);
        BCancel->setObjectName("BCancel");
        BCancel->setFont(font1);

        gridLayout->addWidget(BCancel, 3, 0, 1, 1);

        B2 = new QPushButton(PinFrame);
        B2->setObjectName("B2");
        B2->setFont(font1);

        gridLayout->addWidget(B2, 0, 1, 1, 1);

        B6 = new QPushButton(PinFrame);
        B6->setObjectName("B6");
        B6->setFont(font1);

        gridLayout->addWidget(B6, 1, 2, 1, 1);

        label = new QLabel(pinUInappis);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 651, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(pinUInappis);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 80, 611, 51));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        pirkkal = new QLabel(pinUInappis);
        pirkkal->setObjectName("pirkkal");
        pirkkal->setGeometry(QRect(610, 550, 101, 35));
        frame = new QFrame(pinUInappis);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(230, 150, 251, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        PinLineEdit->raise();
        PinFrame->raise();
        label->raise();
        label_2->raise();
        pirkkal->raise();

        retranslateUi(pinUInappis);

        QMetaObject::connectSlotsByName(pinUInappis);
    } // setupUi

    void retranslateUi(QDialog *pinUInappis)
    {
        pinUInappis->setWindowTitle(QCoreApplication::translate("pinUInappis", "Dialog", nullptr));
        PinLineEdit->setText(QString());
        B4->setText(QCoreApplication::translate("pinUInappis", "4", nullptr));
        B0->setText(QCoreApplication::translate("pinUInappis", "0", nullptr));
        B1->setText(QCoreApplication::translate("pinUInappis", "1", nullptr));
        B9->setText(QCoreApplication::translate("pinUInappis", "9", nullptr));
        B3->setText(QCoreApplication::translate("pinUInappis", "3", nullptr));
        BEnter->setText(QCoreApplication::translate("pinUInappis", "E", nullptr));
        B7->setText(QCoreApplication::translate("pinUInappis", "7", nullptr));
        B8->setText(QCoreApplication::translate("pinUInappis", "8", nullptr));
        B5->setText(QCoreApplication::translate("pinUInappis", "5", nullptr));
        BCancel->setText(QCoreApplication::translate("pinUInappis", "C", nullptr));
        B2->setText(QCoreApplication::translate("pinUInappis", "2", nullptr));
        B6->setText(QCoreApplication::translate("pinUInappis", "6", nullptr));
        label->setText(QCoreApplication::translate("pinUInappis", "Sy\303\266t\303\244 PIN", nullptr));
        label_2->setText(QString());
        pirkkal->setText(QCoreApplication::translate("pinUInappis", "Pirkka Pankki", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pinUInappis: public Ui_pinUInappis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINUINAPPIS_H
