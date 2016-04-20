#pragma once

#include <QMainWindow>
#include "httpserver.h"
#include "htmlroute.h"
#include "htmlserve.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    HtmlRoute route;

private:
    Ui::MainWindow *ui;
    HttpServer *_httpServer;
};

