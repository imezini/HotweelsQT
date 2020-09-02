#include "addveicoli.h"

using std::string;

addVeicoli::addVeicoli(QWidget *parent) : QDialog(parent) {

    setMinimumSize(600,400);
    setWindowTitle("Finestra aggiunta veicoli");
    setWindowTitle("Aggiungi un veicolo");
    mainLayout = new QHBoxLayout(this);

    setLayout(mainLayout);

    tipoVeicolo = new QLabel("Tipo di veicolo: ");
    tipoVeicoloBox = new QComboBox();
    tipoVeicoloBox->addItem("Seleziona il tipo di veicolo");
    tipoVeicoloBox->addItem("Automobile");
    tipoVeicoloBox->addItem("Autocarro < 12 tonnellate");
    tipoVeicoloBox->addItem("Autocarro >= 12 tonnellate");
    tipoVeicoloBox->addItem("Autocarro tipo C");

    targa = new QLabel("Targa: ");
    targaEdit = new QLineEdit();
    targaEdit->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9]{0,7}")));
    targaEdit->setPlaceholderText("es. AA123ZZ");

    marca = new QLabel("Marca: ");
    marcaEdit = new QLineEdit();
    marcaEdit->setPlaceholderText("es. Fiat");

    modello = new QLabel("Modello: ");
    modelloEdit = new QLineEdit();
    modelloEdit->setPlaceholderText("es. Tipo");

    annoImm = new QLabel("Anno Immatricolazione: ");
    annoImmEdit = (new QDateEdit(QDate::currentDate(),this));
    annoImmEdit->setCalendarPopup("es. gg/mm/aa");


    //Label automobile

    classeAmbientale = new QLabel("Classe Ambientale: ");
    classeAmbBox = new QComboBox();
    classeAmbBox->addItem("Seleziona classe ambientale");
    classeAmbBox->addItem("Euro 0");
    classeAmbBox->addItem("Euro 1");
    classeAmbBox->addItem("Euro 2");
    classeAmbBox->addItem("Euro 3");
    classeAmbBox->addItem("Euro 4");
    classeAmbBox->addItem("Euro 5");
    classeAmbBox->addItem("Euro 6");

    potenza = new QLabel("Potenza (Kw): ");
    potenzaEdit = new QSpinBox();
    potenzaEdit->setMaximum(500);

    //Label autocarro

    portata = new QLabel("Portata (t): ");
    portataEdit = new QSpinBox();
    portataEdit->setMinimum(1);
    portataEdit->setMaximum(99);

    //Label autotreno

    numeroAs = new QLabel("Numero Assi: ");
    numeroAsEdit = new QSpinBox();
    numeroAsEdit->setMinimum(2);
    numeroAsEdit->setMaximum(8);

    esoneroCheckbox = new QCheckBox("Esonero bollo", this);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->addRow(tipoVeicolo, tipoVeicoloBox);
    formLayout->addRow(targa, targaEdit);
    formLayout->addRow(marca, marcaEdit);
    formLayout->addRow(modello, modelloEdit);
    formLayout->addRow(annoImm, annoImmEdit);
    formLayout->addRow(classeAmbientale, classeAmbBox);
    formLayout->addRow(potenza, potenzaEdit);
    formLayout->addRow(portata, portataEdit);
    formLayout->addRow(numeroAs, numeroAsEdit);
    formLayout->addRow(esoneroCheckbox);

    mainLayout->addLayout(formLayout);
    verticalLayout = new QVBoxLayout();
    mainLayout->addLayout(verticalLayout);

    salvaButton = new QPushButton("Salva",this);
    annullaButton = new QPushButton("Annulla",this);
    salvaButton->setFixedWidth(100);
    annullaButton->setFixedWidth(100);

    bottoni = new QHBoxLayout();
    bottoni->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    verticalLayout->addLayout(bottoni);
    bottoni->addWidget(salvaButton);
    bottoni->addWidget(annullaButton);

    //Disabilito le Qlabel aggiuntive fino a quando non si seleziona il veicolo

    sblocca(0);

    //PARTE CONNECT

    connect(salvaButton, SIGNAL(clicked()), this, SLOT(conferma()));
    connect(annullaButton, SIGNAL(clicked()), this, SLOT(chiudi()));
    connect(tipoVeicoloBox, SIGNAL(activated(int)), this, SLOT(sblocca(int)));


}

//ok
void addVeicoli::azzeraRighe() {
    tipoVeicoloBox->setCurrentIndex(0);
    targaEdit->setText("");
    marcaEdit->setText("");
    modelloEdit->setText("");
    classeAmbBox->setCurrentIndex(0);
    annoImmEdit->setDate(QDate::currentDate());
    potenzaEdit->setValue(0);
    portataEdit->setValue(1);
    numeroAsEdit->setValue(2);
    esoneroCheckbox->setChecked(false);
}
//ok
void addVeicoli::mostraErroreInput(string motivo){
    QMessageBox erroreInput;
    if(motivo=="mancaLineEdit")
        erroreInput.critical(this,"Errore","Compilare i campi abilitati per poter procedere");
    else if (motivo=="mancaVeicolo")
        erroreInput.critical(this,"Errore","Selezionare il tipo di veicolo");

}



//ok

void addVeicoli:: conferma(){

        if(tipoVeicoloBox->currentIndex()==0)
            emit mostraErroreInput("mancaVeicolo");
        else if((tipoVeicoloBox->currentIndex()==1) && (targaEdit->text()=="" || marcaEdit->text()=="" || modelloEdit->text()=="" || annoImmEdit->text()=="" || classeAmbBox->currentIndex() == 0 || potenzaEdit->value() == 0))
                emit mostraErroreInput("mancaLineEdit");
        else if((tipoVeicoloBox->currentIndex()==2) && (targaEdit->text()=="" || marcaEdit->text()=="" || modelloEdit->text()=="" || annoImmEdit->text()==""))
                emit mostraErroreInput("mancaLineEdit");
        else if((tipoVeicoloBox->currentIndex()==3) && (targaEdit->text()=="" || marcaEdit->text()=="" || modelloEdit->text()=="" || annoImmEdit->text()==""))
                emit mostraErroreInput("mancaLineEdit");
        else {

            QStringList *tmp= new QStringList();
            tmp->push_back(tipoVeicoloBox->currentText());
            tmp->push_back(targaEdit->text());
            tmp->push_back(marcaEdit->text());
            tmp->push_back(modelloEdit->text());
            tmp->push_back(annoImmEdit->date().toString());
            tmp->push_back(classeAmbBox->currentText());
            tmp->push_back(potenzaEdit->text());
            tmp->push_back(portataEdit->text());
            tmp->push_back(numeroAsEdit->text());
            tmp->push_back(esoneroCheckbox->isChecked()? "true":"false");

            this->close();
            this->azzeraRighe();
            sblocca(0);
            emit inviaStringaVeicoli(*tmp);
        }
}

void addVeicoli::chiudi() {
    this->azzeraRighe();
    this->close();
}

//ok
void addVeicoli::sblocca(int n) const {
    switch (n) {
    case 0: //nessun tipo di veicolo selezionato
        classeAmbientale->setEnabled(false);
        classeAmbBox->setEnabled(false);
        potenza->setEnabled(false);
        potenzaEdit->setEnabled(false);
        portata->setEnabled(false);
        portataEdit->setEnabled(false);
        numeroAs->setEnabled(false);
        numeroAsEdit->setEnabled(false);
        break;
    case 1: // automobile
        potenza->setEnabled(true);
        potenzaEdit->setEnabled(true);
        classeAmbientale->setEnabled(true);
        classeAmbBox->setEnabled(true);
        portata->setEnabled(false);
        portataEdit->setEnabled(false);
        numeroAs->setEnabled(false);
        numeroAsEdit->setEnabled(false);
        break;
    case 2: //autocarro < 12 tonnellate
        classeAmbientale->setEnabled(false);
        classeAmbBox->setEnabled(false);
        potenza->setEnabled(false);
        potenzaEdit->setEnabled(false);
        portata->setEnabled(true);
        portataEdit->setEnabled(true);
        numeroAs->setEnabled(false);
        numeroAsEdit->setEnabled(false);
        break;
    case 3: //autocarro >= 12 tonnellate
        classeAmbientale->setEnabled(false);
        classeAmbBox->setEnabled(false);
        potenza->setEnabled(false);
        potenzaEdit->setEnabled(false);
        portata->setEnabled(true);
        portataEdit->setEnabled(true);
        numeroAs->setEnabled(true);
        numeroAsEdit->setEnabled(true);
        break;
    case 4: //autocarro tipo C
        classeAmbientale->setEnabled(true);
        classeAmbBox->setEnabled(true);
        potenza->setEnabled(true);
        potenzaEdit->setEnabled(true);
        portata->setEnabled(true);
        portataEdit->setEnabled(true);
        numeroAs->setEnabled(false);
        numeroAsEdit->setEnabled(false);
        break;
    }
}

