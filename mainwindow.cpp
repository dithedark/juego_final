#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_window();
    setup_juego();
}

void MainWindow::setup_window()
{
    setWindowTitle("saltarin");
    setMaximumSize(16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    setMinimumSize(16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
}

void MainWindow::setup_juego()
{
    scene = new juego;
    ui->graphicsView->setGeometry(0,0,16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete bl;
}

