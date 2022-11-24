#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "button.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_window();
    menu_inicio();
}

void MainWindow::setup_window()
{
    setWindowTitle("saltarin");
    setMaximumSize(16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    setMinimumSize(16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
}

void MainWindow::menu_inicio(){
    scene = new juego;
    ui->graphicsView->setGeometry(0,0,16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    ui->graphicsView->setScene(scene);

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("SALTARIN"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Jugar"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(iniciar_juego()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Salir"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void MainWindow::setup_juego()
{
    scene = new juego;
    scene->iniciar_juego();
    ui->graphicsView->setGeometry(0,0,16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    ui->graphicsView->setScene(scene);
}

void MainWindow::iniciar_juego(){
    delete scene;
    setup_juego();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;

}

