QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditordebitwindow.cpp \
    main.cpp \
    mainexewindow.cpp \
    mainwindow.cpp \
    otheramount.cpp \
    ottowindow.cpp \
    receiptselection.cpp \
    receiptwindow.cpp \
    saldowindow.cpp \
    takemoney.cpp \
    transactionwindow.cpp \
    transferwindow.cpp

HEADERS += \
    creditordebitwindow.h \
    mainexewindow.h \
    mainwindow.h \
    otheramount.h \
    ottowindow.h \
    receiptselection.h \
    receiptwindow.h \
    saldowindow.h \
    takemoney.h \
    transactionwindow.h \
    transferwindow.h

FORMS += \
    creditordebitwindow.ui \
    mainexewindow.ui \
    mainwindow.ui \
    otheramount.ui \
    ottowindow.ui \
    pinUIDLL/pinuinappis.ui \
    receiptselection.ui \
    receiptwindow.ui \
    saldowindow.ui \
    takemoney.ui \
    transactionwindow.ui \
    transferwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \          # ELKÄÄ POISTAKO
    gifsANDicons.qrc    # T. EMPPU





macx|win32: LIBS += -L$$PWD/DLLRestAPI/build/ -lDLLRestAPI.1.0.0

INCLUDEPATH += $$PWD/DLLRestAPI
DEPENDPATH += $$PWD/DLLRestAPI

macx|win32: LIBS += -L$$PWD/rfid_dll/build/ -lrfid_dll.1.0.0

INCLUDEPATH += $$PWD/rfid_dll
DEPENDPATH += $$PWD/rfid_dll

macx|win32: LIBS += -L$$PWD/pinUIDLL/build/ -lpinUIDLL.1.0.0

INCLUDEPATH += $$PWD/pinUIDLL
DEPENDPATH += $$PWD/pinUIDLL
