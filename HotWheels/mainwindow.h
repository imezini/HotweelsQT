#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QMenuBar>
#include <QAction>
#include "viewlistaveicoli.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btncalcola_clicked(bool checked);

private:
    QVBoxLayout* mainLayout, *verticalLayout;
    QHBoxLayout* horizontal;
    viewListaVeicoli* listaVeicoli;
    QPushButton* removeFilter, *checkAutomobile, *checkAutocarro, *checkAutotreno, *checkMinAssi, *checkMaxAssi, *checkEsonero;
    QPushButton* addButton,*modButton,*removeButton;
    //void setMainWindowStyle(); Forse serve per lo stile css

};

#endif // MAINWINDOW_H
