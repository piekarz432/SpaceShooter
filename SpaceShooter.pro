QT       += core gui \
         multimedia \
         uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    achievement.cpp \
    asteroid.cpp \
    bonus.cpp \
    bullet.cpp \
    button.cpp \
    enemy.cpp \
    entity.cpp \
    game.cpp \
    gameoverwindow.cpp \
    healthbar.cpp \
    highscore.cpp \
    main.cpp \
    mainMenu.cpp \
    mainwindow.cpp \
    score.cpp \
    shield.cpp \
    ship.cpp \
    shopwindow.cpp \
    storage.cpp

HEADERS += \
    achievement.h \
    asteroid.h \
    bonus.h \
    bullet.h \
    button.h \
    enemy.h \
    entity.h \
    game.h \
    gameoverwindow.h \
    healthbar.h \
    highscore.h \
    mainMenu.h \
    mainwindow.h \
    score.h \
    shield.h \
    ship.h \
    shopwindow.h \
    storage.h

FORMS += \
    achievement.ui \
    form.ui \
    gameoverwindow.ui \
    highscore.ui \
    mainwindow.ui \
    shopwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
