QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addproduct.cpp \
    adduser.cpp \
    adminwindow.cpp \
    checkouttt.cpp \
    editproduct.cpp \
    edituser.cpp \
    globalusers.cpp \
    loginadmin.cpp \
    main.cpp \
    mainwindow.cpp \
    productclass.cpp \
    productmanager.cpp \
    products.cpp \
    register.cpp \
    shoppingcart.cpp \
    userlogin.cpp \
    users.cpp \
    userwindow.cpp

HEADERS += \
    addproduct.h \
    adduser.h \
    adminwindow.h \
    checkouttt.h \
    editproduct.h \
    edituser.h \
    globalusers.h \
    loginadmin.h \
    mainwindow.h \
    productclass.h \
    productmanager.h \
    products.h \
    register.h \
    shoppingcart.h \
    userlogin.h \
    users.h \
    userwindow.h

FORMS += \
    addproduct.ui \
    adduser.ui \
    adminwindow.ui \
    checkouttt.ui \
    editproduct.ui \
    edituser.ui \
    loginadmin.ui \
    mainwindow.ui \
    productmanager.ui \
    products.ui \
    register.ui \
    userlogin.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
