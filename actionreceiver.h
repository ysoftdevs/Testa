#ifndef ACTIONRECEIVER_H
#define ACTIONRECEIVER_H

#include <QObject>
#include <QtWebSockets>

class ActionReceiver : public QObject
{
    Q_OBJECT
public:
    explicit ActionReceiver(const QUrl &address, QObject *parent = 0);
    ~ActionReceiver();
private slots:
    void socketConnected();
    void socketReceivedStringMessage(const QString &message);
    void socketError(QAbstractSocket::SocketError socketError);
signals:
    void loadUrlReceived(QString);
    void setProgressReceived(float);
    void showNotificationReceived(QString, QString);
private:
    QUrl address;
    QWebSocket* webSocket;

    QString getActionType(const QJsonObject &jsonObject);
    QJsonObject getParameters(const QJsonObject &jsonObject);
};

#endif // ACTIONRECEIVER_H
