#include "ddeglobalmenutheme.h"
#include "qdbusmenubar_p.h"
#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDebug>
#include <KWindowSystem>

static const QByteArray s_x11AppMenuServiceNamePropertyName = QByteArrayLiteral("_KDE_NET_WM_APPMENU_SERVICE_NAME");
static const QByteArray s_x11AppMenuObjectPathPropertyName = QByteArrayLiteral("_KDE_NET_WM_APPMENU_OBJECT_PATH");

DDEGlobalMenuTheme::DDEGlobalMenuTheme()
{
    m_x11Integration.reset(new X11Integration());
    m_x11Integration->init();
}

QPlatformMenuBar *DDEGlobalMenuTheme::createPlatformMenuBar() const
{
    if (true) {
        auto *menu = new QDBusMenuBar();

        QObject::connect(menu, &QDBusMenuBar::windowChanged, menu, [this, menu](QWindow *newWindow, QWindow *oldWindow) {
            const QString &serviceName = QDBusConnection::sessionBus().baseService();
            const QString &objectPath = menu->objectPath();

            if (m_x11Integration) {
                if (oldWindow) {
                    m_x11Integration->setWindowProperty(oldWindow, s_x11AppMenuServiceNamePropertyName, {});
                    m_x11Integration->setWindowProperty(oldWindow, s_x11AppMenuObjectPathPropertyName, {});
                }

                if (newWindow) {
                    m_x11Integration->setWindowProperty(newWindow, s_x11AppMenuServiceNamePropertyName, serviceName.toUtf8());
                    m_x11Integration->setWindowProperty(newWindow, s_x11AppMenuObjectPathPropertyName, objectPath.toUtf8());
                }
            }

            qDebug() << serviceName << objectPath;
        });

        return menu;
    }

    return nullptr;
}
