#include <qpa/qplatformthemeplugin.h>
#include "ddeglobalmenutheme.h"

QT_BEGIN_NAMESPACE

class DDEGlobalMenuPlugin : public QPlatformThemePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformThemeFactoryInterface_iid FILE "dde-globalmenu.json")

public:
    QPlatformTheme *create(const QString &key, const QStringList &params) Q_DECL_OVERRIDE;
};

QPlatformTheme *DDEGlobalMenuPlugin::create(const QString &key, const QStringList &params)
{
    Q_UNUSED(params)
    Q_UNUSED(key)
    return new DDEGlobalMenuTheme;
}

QT_END_NAMESPACE

#include "main.moc"
