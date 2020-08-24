#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent), vistaAdd(new addVeicoli()), vistaMod(new modVeicoli()) {

    setMinimumSize(950,600);
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

    setMainWindowStyle();
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
    gridFilter->addWidget(removeFilter, 1, 2);
    gridFilter->addWidget(checkEsonero, 2, 2);

    allFilter->setLayout(gridFilter);
    verticalLayout->addWidget(allFilter);

    /*tabella veicoli*/

    veicoliTable= new QTableWidget();
    verticalLayout->addWidget(veicoliTable);
    veicoliTable->setRowCount(1);
    veicoliTable->setColumnCount(9);
    header << "Targa" << "Marca" << "Modello" << "Cl.Ambientale" << "Anno Immatr." << "Potenza" << "Peso" << "Numero Assi"<< "Bollo";
    veicoliTable->setHorizontalHeaderLabels(header);
    veicoliTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//        QStringList *prova = new QStringList();
//        prova->push_back("targa");
//        prova->push_back("targa");
//        prova->push_back("targa");
//        prova->push_back("targa");
//        prova->push_back("cacca");
//        prova->push_back("targa");
//        prova->push_back("targa");
//        prova->push_back("targa");
//        prova->push_back("targa");
//            for(int a = 0; a < 9; a++) {
//                veicoliTable->setItem(0, a, new QTableWidgetItem(prova->at(a)));
//            }



    /*Veicoli*/

    QGroupBox *veicoliGroup = new QGroupBox("Lista Veicoli");
    QVBoxLayout *layoutListaVeicoli= new QVBoxLayout();
    lineCerca = new QLineEdit(this);
    lineCerca->setPlaceholderText("Cerca Veicolo");
    layoutListaVeicoli->addWidget(lineCerca);
    layoutListaVeicoli->addWidget(veicoliTable);
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

    connect(addButton, SIGNAL(clicked()), this, SLOT(openAddLayout()));
    connect(modButton, SIGNAL(clicked()), this, SLOT(openModLayout()));


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
}



MainWindow::~MainWindow()
{

}

void MainWindow::openAddLayout() {
    vistaAdd->show();
}

void MainWindow::openModLayout() {
    vistaMod->show();
}


// colori+css

void MainWindow::setMainWindowStyle(){
    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}

void MainWindow:: colorInizio() const{
    checkAutomobile->setStyleSheet("background-color:#ADD8E6;");
    checkAutocarro->setStyleSheet("background-color:#ADD8E6;");
    checkAutotreno->setStyleSheet("background-color:#ADD8E6;");
    checkMinAssi->setStyleSheet("background-color:#ADD8E6;");
    checkMaxAssi->setStyleSheet("background-color:#ADD8E6;");
    checkEsonero->setStyleSheet("background-color:#ADD8E6;");

}


void MainWindow::colorAutomobile(){
    checkAutomobile->setStyleSheet("background-color:#3cb043;");
    checkAutocarro->setStyleSheet("background-color:#ADD8E6;");
    checkAutotreno->setStyleSheet("background-color:#ADD8E6;");
    checkMinAssi->setStyleSheet("background-color:#ADD8E6;");
    checkMaxAssi->setStyleSheet("background-color:#ADD8E6;");
    checkEsonero->setStyleSheet("background-color:#ADD8E6;");


}

void MainWindow::colorAutotreno(){
    checkAutomobile->setStyleSheet("background-color:#ADD8E6;");
    checkAutocarro->setStyleSheet("background-color:#ADD8E6;");
    checkAutotreno->setStyleSheet("background-color:#3cb043;");
    checkMinAssi->setStyleSheet("background-color:#ADD8E6;");
    checkMaxAssi->setStyleSheet("background-color:#ADD8E6;");
    checkEsonero->setStyleSheet("background-color:#ADD8E6;");
}

void MainWindow::colorAutocarro(){
    checkAutomobile->setStyleSheet("background-color:#ADD8E6;");
    checkAutocarro->setStyleSheet("background-color:#3cb043;");
    checkAutotreno->setStyleSheet("background-color:#ADD8E6;");
    checkMinAssi->setStyleSheet("background-color:#ADD8E6;");
    checkMaxAssi->setStyleSheet("background-color:#ADD8E6;");
    checkEsonero->setStyleSheet("background-color:#ADD8E6;");
}

void MainWindow::colorMinAssi(){
    checkAutomobile->setStyleSheet("background-color:#ADD8E6;");
    checkAutocarro->setStyleSheet("background-color:#ADD8E6;");
    checkAutotreno->setStyleSheet("background-color:#ADD8E6;");
    checkMinAssi->setStyleSheet("background-color:#3cb043;");
    checkMaxAssi->setStyleSheet("background-color:#ADD8E6;");
    checkEsonero->setStyleSheet("background-color:#ADD8E6;");
}

void MainWindow::colorMaxAssi(){
    checkAutomobile->setStyleSheet("background-color:#ADD8E6;");
    checkAutocarro->setStyleSheet("background-color:#ADD8E6;");
    checkAutotreno->setStyleSheet("background-color:#ADD8E6;");
    checkMinAssi->setStyleSheet("background-color:#ADD8E6;");
    checkMaxAssi->setStyleSheet("background-color:#3cb043;");
    checkEsonero->setStyleSheet("background-color:#ADD8E6;");
}

void MainWindow::colorEsonero(){
    checkAutomobile->setStyleSheet("background-color:#ADD8E6;");
    checkAutocarro->setStyleSheet("background-color:#ADD8E6;");
    checkAutotreno->setStyleSheet("background-color:#ADD8E6;");
    checkMinAssi->setStyleSheet("background-color:#ADD8E6;");
    checkMaxAssi->setStyleSheet("background-color:#ADD8E6;");
    checkEsonero->setStyleSheet("background-color:#3cb043;");
}

//void MainWindow::mostraVeicoli(const QStringList targaVeicoli){
//    int i = 0;
//    auto it = targaVeicoli.begin();
//    while(it != targaVeicoli.end()){
//        veicoliTable->insertRow(i);
//        veicoliTable->setItem(i,1,new QTableWidgetItem(targaVeicoli.at(i)));
//        ++it;
//        ++i;
//    }
//}

