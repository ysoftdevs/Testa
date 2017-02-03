#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>

#include "webengineview.h"
#include "actionreceiver.h"

class ApplicationController : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationController(WebEngineView *webEngineView, ActionReceiver *actionReceiver, QObject *parent = 0);
    void test();
private:    
    WebEngineView* webEngineView;
    ActionReceiver* actionReceiver;
};

#endif // APPLICATIONCONTROLLER_H
