#ifndef DDEGLOBALMENUTHEME_H
#define DDEGLOBALMENUTHEME_H

#include <qpa/qplatformtheme.h>
#include <QScopedPointer>
#include "x11integration.h"

class DDEGlobalMenuTheme : public QPlatformTheme
{
public:
    DDEGlobalMenuTheme();
    QPlatformMenuBar *createPlatformMenuBar() const override;

    static const char *name;

private:
    QScopedPointer<X11Integration> m_x11Integration;
};

#endif // DDEGLOBALMENUTHEME_H
