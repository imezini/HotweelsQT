#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent), vistaAdd(new addVeicoli(this)), vistaMod(new modVeicoli(this)) {

    setMinimumSize(1150,700);
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

    /*tabella veicoli*/

    veicoliTable = new QTableWidget();
    verticalLayout->addWidget(veicoliTable);
    veicoliTable->setColumnCount(11);
    header <<"Tipo Veicolo" << "Targa" << "Marca" << "Modello" << "Anno Immatr." << "Cl.Ambientale" << "Potenza" << "Portata" << "Numero Assi" <<"Esonero" << "Bollo";
    veicoliTable->setHorizontalHeaderLabels(header);
    veicoliTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    /*Veicoli*/

    QGroupBox *veicoliGroup = new QGroupBox("Lista Veicoli");
    QVBoxLayout *layoutListaVeicoli= new QVBoxLayout();
    lineCerca = new QLineEdit(this);
    lineCerca->setPlaceholderText("Filtra Tabella");
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
    //connect(modButton, SIGNAL(clicked()), this, SLOT(openModLayout()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(richiestaRim()));
    connect(lineCerca, SIGNAL(textChanged(QString)), this, SLOT(cercaParola(QString)));

}

MainWindow::~MainWindow()
{

}

void MainWindow::openAddLayout() const {
    vistaAdd->show();
}


void MainWindow::richiestaRim() {
        emit sEliminav(veicoliTable->currentRow());
}

void MainWindow::cercaParola(QString parolaCercata) {
    for( int i = 0; i < veicoliTable->rowCount(); ++i ) {
        bool match = false;
        for( int j = 0; j < veicoliTable->columnCount(); ++j ){
            QTableWidgetItem *item = veicoliTable->item(i, j );
            if(item->text().contains(parolaCercata)){
                match = true;
                break;
            }
        }
        veicoliTable->setRowHidden(i, !match);
    }
}

void MainWindow::veicoloAggiunto(){
    QMessageBox veicoloAggiuntoBox;
    veicoloAggiuntoBox.information(this,"Veicolo aggiunto","Il veicolo è stato aggiunto con successo!");
}

void MainWindow::mostraVeicoli(QList<QStringList> targaVeicoli){
    int r = 1;
    for(auto it = targaVeicoli.begin(); it != targaVeicoli.end(); it++){
        veicoliTable->setRowCount(r);
        for(int c = 0; c < 11; c++){
             veicoliTable->setItem(r-1, c, new QTableWidgetItem(targaVeicoli.at(r-1)[c]));
        }
        r++;
    }
}

const QString MainWindow::getParolaCercata() const {
    return lineCerca->text();
}

void MainWindow::nessunSelezionato() {
    QMessageBox rimuoviNonSelezionato;
    rimuoviNonSelezionato.critical(this,"Nessun veicolo selezionato","Selezionare un veicolo");
}

void MainWindow::veicoloRimossoShowBox() {
    QMessageBox veicoloRimossoBox;
    veicoloRimossoBox.information(this,"Veicolo rimosso","Il veicolo è stato rimosso con successo");
}
void MainWindow::targaPresenteBox() {
    QMessageBox targaPresenteBox;
    targaPresenteBox.critical(this, "Targa già presente nella lista", "Non è possibile aggiungere due veicoli con targa uguale");
}

// colori+css

void MainWindow::setMainWindowStyle(){
    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}


