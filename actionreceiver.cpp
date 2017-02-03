#include "actionreceiver.h"

ActionReceiver::ActionReceiver(const QUrl& address, QObject *parent)
    : QObject(parent),
      address(address),
      webSocket(new QWebSocket())
{
    connect(webSocket, &QWebSocket::connected, this, &ActionReceiver::socketConnected);
    connect(webSocket, &QWebSocket::textMessageReceived, this, &ActionReceiver::socketReceivedStringMessage);
    connect(webSocket, static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), this, &ActionReceiver::socketError);

    webSocket->open(address);
}

ActionReceiver::~ActionReceiver()
{
    webSocket->close();
    delete webSocket;
}

void ActionReceiver::socketConnected()
{
    qInfo() << "Socket connected to server";
}

void ActionReceiver::socketReceivedStringMessage(const QString &message)
{
    QJsonDocument jsonDocument =  QJsonDocument::fromJson(message.toUtf8());
    QJsonObject jsonObject = jsonDocument.object();

    QString messageType = getActionType(jsonObject);
    QJsonObject parameters = getParameters(jsonObject);

    if (messageType == "loadUrl") {
        emit loadUrlReceived(parameters["url"].toString());
    } else if (messageType == "showNotification") {
        const QString title = parameters["title"].toString();
        const QString message = parameters["message"].toString();
        emit showNotificationReceived(title, message);
    } else if (messageType == "setProgress") {
        float value = parameters["value"].toDouble();
        emit setProgressReceived(value);
    } else {
        qWarning() << "Unsupported action type [" << messageType << "]";
    }
}

void ActionReceiver::socketError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    qWarning() << "There was an error:" << webSocket->errorString();
}

QString ActionReceiver::getActionType(const QJsonObject &jsonObject)
{
    return jsonObject["action"].toString();
}

QJsonObject ActionReceiver::getParameters(const QJsonObject &jsonObject)
{
    return jsonObject["parameters"].toObject();
}
