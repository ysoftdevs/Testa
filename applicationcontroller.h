#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>
#include <QJsonObject>
#include <QAbstractSocket>
#include <QtWebSockets/QWebSocket>
#include "webengineview.h"

class ApplicationController : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationController(WebEngineView *webEngineView, QObject *parent = 0);
    void test();
private slots:
    void connected();
    void messageReceived(const QString &message);
    void error(QAbstractSocket::SocketError error);
private:
    QWebSocket* webSocket;
    WebEngineView* webEngineView;

    QString getMessageType(const QJsonObject &jsonObject);
    QJsonObject getParameters(const QJsonObject &jsonObject);
};

#endif // APPLICATIONCONTROLLER_H
