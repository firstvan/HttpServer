#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    route.Register("/", HtmlServe::index);
    route.Register("/second", HtmlServe::second);
    route.Register("/dogs", HtmlServe::dogs);

    _httpServer = new HttpServer(route);

}

MainWindow::~MainWindow()
{
    delete _httpServer;
    delete ui;
}
