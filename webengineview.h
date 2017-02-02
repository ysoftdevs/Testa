#ifndef WEBENGINEVIEW_H
#define WEBENGINEVIEW_H

#include <QtCore/QtGlobal>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>

class WebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    WebEngineView();

public Q_SLOTS:
    void showCustomContextMenu(const QPoint&);
    void loadUrl(QUrl url);
};

#endif // WEBENGINEVIEW_H
