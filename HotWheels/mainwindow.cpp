#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), listaVeicoli(new viewListaVeicoli(this)) {

    setWindowTitle("Controlla Bollo");
    mainLayout = new QVBoxLayout(this);

    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* menu = new QMenu("File", menuBar);
    QAction* save = new QAction("Salva", menu);
    save->setShortcut(Qt::Key_S | Qt::CTRL);
    QAction* exit = new QAction("Esci", menu);

    menu->addAction(save);
    menu->addAction(exit);
    menuBar->addMenu(menu);
    mainLayout->addWidget(menuBar);

    //setMainWindowStyle();
    verticalLayout = new QVBoxLayout();
    horizontal = new QHBoxLayout();
    mainLayout->addLayout(horizontal);
    horizontal->addLayout(verticalLayout);

    setLayout(mainLayout);

    /*Filtri*/

    QGroupBox* allFilter = new QGroupBox("Filtri");
    QGridLayout* gridFilter = new QGridLayout();
    removeFilter = new QPushButton("Rimuovi Filtri", this);
    checkAutomobile = new QPushButton("Automobile", this);
    checkAutocarro = new QPushButton("Autocarro", this);
    checkAutotreno = new QPushButton("Autotreno", this);
    checkMinAssi = new QPushButton("2 assi", this);
    checkMaxAssi = new QPushButton("Maggiore di 2 assi", this);
    checkEsonero = new QPushButton("Esonero", this);

    gridFilter->addWidget(checkAutomobile, 0, 0);
    gridFilter->addWidget(checkAutocarro, 0, 1);
    gridFilter->addWidget(checkAutotreno, 0, 2);
    gridFilter->addWidget(checkMinAssi, 1, 0);
    gridFilter->addWidget(checkMaxAssi, 1, 1);
    gridFilter->addWidget(checkEsonero, 1, 2);
    gridFilter->addWidget(removeFilter, 2, 2);

    allFilter->setLayout(gridFilter);
    verticalLayout->addWidget(allFilter);



    /*
    addButton = new QPushButton("Aggiungi",this);
    addButton->setMinimumWidth(110);
    modButton = new QPushButton("Modifica",this);
    modButton->setMinimumWidth(110);
    removeButton = new QPushButton("Rimuovi",this);
    removeButton->setMinimumWidth(110);
 */
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_btncalcola_clicked(bool checked)
{

}
