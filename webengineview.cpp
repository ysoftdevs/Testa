#include <QtGlobal>
#include <QtWidgets/QMenu>
#include <QtGui/QContextMenuEvent>
#include <QSystemTrayIcon>

#include "webengineview.h"

WebEngineView::WebEngineView()
    : QWebEngineView()
{
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showCustomContextMenu(const QPoint&)));

    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    resize(1024, 750); // TODO: from config
}

void WebEngineView::showCustomContextMenu(const QPoint& a_pos)
{
    QAction printPageAction("YSoft!",  NULL);
    connect(&printPageAction, SIGNAL(triggered()), this, SLOT(printPage()));

    QAction openPageInBrowserAction("Custom context menu?", NULL);   

    QMenu* contextMenu = new QMenu(this);
    contextMenu->addAction(&printPageAction);
    contextMenu->addAction(&openPageInBrowserAction);
    contextMenu->exec(mapToGlobal(a_pos));

    delete contextMenu;
}

void WebEngineView::loadUrl(QUrl url)
{
    setUrl(url);
    show();
}
