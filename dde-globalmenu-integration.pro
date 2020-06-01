QT       += dbus x11extras
QT += KWindowSystem
QT       += core-private gui-private
greaterThan(QT_MAJOR_VERSION, 4) {
  QT += widgets widgets-private
  # Qt >= 5.8
  greaterThan(QT_MAJOR_VERSION, 5)|greaterThan(QT_MINOR_VERSION, 7): QT += theme_support-private
  else: QT += platformsupport-private
}

TARGET = dde-globalmenu
TEMPLATE = lib
CONFIG += plugin link_pkgconfig c++11

PLUGIN_TYPE = platformthemes
PLUGIN_EXTENDS = -
PLUGIN_CLASS_NAME = DDEGlobalMenuTheme

SOURCES += \
        main.cpp \
    ddeglobalmenutheme.cpp \
    qdbusmenubar.cpp \
    x11integration.cpp

DISTFILES += \
    dde-globalmenu.json

unix {
    target.path = $$[QT_INSTALL_PLUGINS]/platformthemes
    INSTALLS += target
}

HEADERS += \
    ddeglobalmenutheme.h \
    qdbusmenubar_p.h \
    x11integration.h
