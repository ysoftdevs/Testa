#include <QJsonDocument>
#include "applicationcontroller.h"
#include "notification.h"
#include "progressbar.h"

ApplicationController::ApplicationController(WebEngineView* webEngineView, QObject *parent) :
    QObject(parent),
    webEngineView(webEngineView),
    webSocket(new QWebSocket())
{
    connect(webSocket, &QWebSocket::connected, this, &ApplicationController::connected);
    connect(webSocket, &QWebSocket::textMessageReceived, this, &ApplicationController::messageReceived);
    connect(webSocket, static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), this, &ApplicationController::error);

    webSocket->open(QUrl("ws://localhost:12345")); // TODO: extract to configuration
}

void ApplicationController::connected()
{
    qDebug() << "Connected";
}

void ApplicationController::messageReceived(const QString &message)
{
    QJsonDocument jsonDocument =  QJsonDocument::fromJson(message.toUtf8());
    QJsonObject jsonObject = jsonDocument.object();

    QString messageType = getMessageType(jsonObject);
    QJsonObject parameters = getParameters(jsonObject);

    if (messageType == "loadUrl") {
        QUrl url(parameters["url"].toString());

        webEngineView->loadUrl(url);
    } else if (messageType == "showNotification") {
        const QString title = parameters["title"].toString();
        const QString message = parameters["message"].toString();

        Notification::show(title.toStdString(), message.toStdString());
    } else if (messageType == "setProgress") {
        float value = parameters["value"].toDouble();

        ProgressBar::show(value);
    }
}
void ApplicationController::error(QAbstractSocket::SocketError error)
{
    qDebug() << webSocket->errorString();
}

QString ApplicationController::getMessageType(const QJsonObject &jsonObject)
{
    return jsonObject["action"].toString();
}

QJsonObject ApplicationController::getParameters(const QJsonObject &jsonObject)
{
    return jsonObject["parameters"].toObject();
}
