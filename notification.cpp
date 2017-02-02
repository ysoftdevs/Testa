#include <QSystemTrayIcon>

#include "notification.h"

static QSystemTrayIcon* sharedSystemTrayIcon;

void Notification::show(const std::string& title, const std::string& message)
{
    if (sharedSystemTrayIcon == nullptr)
        sharedSystemTrayIcon = new QSystemTrayIcon();
    sharedSystemTrayIcon->show();
    sharedSystemTrayIcon->showMessage(QString::fromStdString(title), QString::fromStdString(message));
}

void Notification::hide()
{
    sharedSystemTrayIcon->hide();
    delete sharedSystemTrayIcon;
}
