#include <QApplication>

#include "mainwindow.h"
#include "webengineview.h"
#include "applicationcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::ApplicationAttribute::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    WebEngineView view;   

    ApplicationController applicationController(&view);

    return a.exec();
}
