#include "applicationcontroller.h"
#include "notification.h"
#include "progressbar.h"

ApplicationController::ApplicationController(WebEngineView* webEngineView, ActionReceiver *actionReceiver, QObject *parent) :
    QObject(parent),    
    webEngineView(webEngineView),
    actionReceiver(actionReceiver)
{
    connect(actionReceiver, &ActionReceiver::showNotificationReceived, Notification::show);
    connect(actionReceiver, &ActionReceiver::setProgressReceived, ProgressBar::show);
    connect(actionReceiver, &ActionReceiver::loadUrlReceived, webEngineView, &WebEngineView::loadUrl);
}

