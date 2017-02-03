#include <QApplication>

#include "webengineview.h"
#include "applicationcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::ApplicationAttribute::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    WebEngineView view;   
    ActionReceiver actionReceiver(QUrl("ws://localhost:12345"));
    ApplicationController applicationController(&view, &actionReceiver);

    return a.exec();
}
