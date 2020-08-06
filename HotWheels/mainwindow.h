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
#include <QAbstractItemView>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QTableWidget>
#include <QTableView>

#include <QStringList>
#include <QSizePolicy>


#include "viewlistaveicoli.h"
#include "pointer.h"
#include "addveicoli.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:



private:
    QVBoxLayout* mainLayout, *verticalLayout;
    QHBoxLayout* horizontal, *Bottonisotto;
    viewListaVeicoli* listaVeicoli;
    QPushButton* removeFilter, *checkAutomobile, *checkAutocarro, *checkAutotreno, *checkMinAssi, *checkMaxAssi, *checkEsonero;
    QPushButton* addButton,*modButton,*removeButton;
    QLineEdit* lineCerca;
    QGroupBox* veicoliGroup1;
    QTableWidget* veicoliTable;
    QStringList header;
    addVeicoli* vista;
    //void setMainWindowStyle(); Forse serve per lo stile css

signals:
    void openAddVeicoli();

};

#endif // MAINWINDOW_H
