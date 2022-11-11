#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bloques.h"
#include "macros.h"
#include "juego.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setup_window();
    void setup_juego();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    juego *scene;

};
#endif // MAINWINDOW_H
