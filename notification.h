#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QObject>
#include <string>

class Notification : public QObject
{
    Q_OBJECT
public slots:
    static void show(const QString &title, const QString &message);
    static void hide();
private:
    Notification() { }
};

#endif // NOTIFICATION_H
