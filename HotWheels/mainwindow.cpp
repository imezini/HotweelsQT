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

    /*Veicoli*/

    QGroupBox *veicoliGroup = new QGroupBox("Lista Veicoli");
    listaVeicoli->setSelectionMode(QAbstractItemView::SingleSelection);
    QVBoxLayout *layoutListaVeicoli= new QVBoxLayout();
    lineCerca = new QLineEdit(this);
    lineCerca->setPlaceholderText("Cerca Veicolo");
    layoutListaVeicoli->addWidget(lineCerca);
    layoutListaVeicoli->addWidget(listaVeicoli);
    veicoliGroup->setLayout(layoutListaVeicoli);
    addButton = new QPushButton("Aggiungi veicolo",this);
    addButton->setMinimumWidth(110);
    modButton = new QPushButton("Modifica veicolo",this);
    modButton->setMinimumWidth(110);
    removeButton = new QPushButton("Rimuovi veicolo",this);
    removeButton->setMinimumWidth(110);

    verticalLayout->addWidget(veicoliGroup);

    Bottonisotto = new QHBoxLayout();
    verticalLayout->addLayout(Bottonisotto);
    Bottonisotto->addWidget(addButton);
    Bottonisotto->addWidget(modButton);
    Bottonisotto->addWidget(removeButton);

    /*tabella veicoli*/

    veicoliTable= new QTableWidget();
    verticalLayout->addWidget(veicoliTable);
    veicoliTable -> setRowCount(1);
    veicoliTable -> setColumnCount(8);
    header << "1" << "2" << "3" << "4" << "5" << "6" << "8" << "9";
    veicoliTable->setHorizontalHeaderLabels(header);
    veicoliTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    veicoliTable->horizontalHeader()->setStretchLastSection(true);








    /*Bollo*/

     QGroupBox *veicoliGroup1 = new QGroupBox("Bollo");
     QFormLayout *formBolloLayout = new QFormLayout();
     QLabel *totaleLabel = new QLabel(tr("Totale bollo veicoli selezionati: "));
     formBolloLayout->addRow(totaleLabel);
     veicoliGroup1->setLayout(formBolloLayout);
     verticalLayout->addWidget(veicoliGroup1);

     /*Parte grafica*/

     checkAutomobile->setObjectName(QStringLiteral("checkAutomobile"));
     checkAutocarro->setObjectName(QStringLiteral("checkAutocarro"));
     checkAutotreno->setObjectName(QStringLiteral("checkAutotreno"));
     checkEsonero->setObjectName(QStringLiteral("checkEsonero"));
     checkMaxAssi->setObjectName(QStringLiteral("checkMaxAssi"));
     checkMinAssi->setObjectName(QStringLiteral("checkMinAssi"));
     removeFilter->setObjectName(QStringLiteral("removeFilter"));


     /*Parte connect */
     connect(addButton, SIGNAL(clicked()), this, SIGNAL(openAddVeicoli()));


}



MainWindow::~MainWindow()
{

}

//void MainWindow::openAddVeicoli()
//{
//    vista = new addVeicoli();
//    vista->show();
//}

