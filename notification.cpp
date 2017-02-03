#include <QSystemTrayIcon>

#include "notification.h"

static QSystemTrayIcon* sharedSystemTrayIcon;

void Notification::show(const QString &title, const QString &message)
{
    if (sharedSystemTrayIcon == nullptr)
        sharedSystemTrayIcon = new QSystemTrayIcon();
    sharedSystemTrayIcon->show();
    sharedSystemTrayIcon->showMessage(title, message);
}

void Notification::hide()
{
    sharedSystemTrayIcon->hide();
    delete sharedSystemTrayIcon;
}
