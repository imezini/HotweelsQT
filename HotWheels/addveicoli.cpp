#include "addveicoli.h"

using std::string;

addVeicoli::addVeicoli(QWidget *parent) : QWidget(parent) {

    setMinimumSize(500,400);
    setWindowTitle("Finestra aggiunta veicoli");
    setWindowTitle("Aggiungi un veicolo");
    mainLayout=new QHBoxLayout(this);
   // QHBoxLayout *mainLayout = new QHBoxLayout();

    setLayout(mainLayout);


    QLabel *marca = new QLabel("(*)Marca: ");
    marcaEdit = new QLineEdit();
    marcaEdit->setPlaceholderText("es. Fiat");

    QLabel *modello = new QLabel("(*)Modello: ");
    modelloEdit = new QLineEdit();
    modelloEdit->setPlaceholderText("es. Tipo");

    QLabel *classeAmb = new QLabel("(*)Classe Ambientale: ");
    classeAmbEdit = new QLineEdit();
    classeAmbEdit->setPlaceholderText("es. Euro 6");

    QLabel *annoImm = new QLabel("(*)Anno Immatricolazione: ");
    annoImmEdit = (new QDateEdit(QDate::currentDate(),this));
    annoImmEdit->setCalendarPopup("es. aa/mm/gg");

    QLabel *potenza = new QLabel("(*)Potenza (Kw): ");
    potenzaEdit = new QLineEdit();
    potenzaEdit->setPlaceholderText("es. 80");

    QLabel *peso = new QLabel("(*)Peso (t): ");
    pesoEdit = new QLineEdit();
    pesoEdit->setPlaceholderText("es. 15");

    QLabel *numeroAs = new QLabel("(*)Numero Assi: ");
    numeroAsEdit = new QLineEdit();
    numeroAsEdit->setPlaceholderText("es. 3");

    automobileCheckbox = new QCheckBox("Automobile",this);
    autotrenoCheckbox = new QCheckBox("Autotreno",this);
    autocarroCheckbox = new QCheckBox("Autocarro",this);
    esoneroCheckbox = new QCheckBox("Esonero bollo",this);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->addRow(marca, marcaEdit);
    formLayout->addRow(modello, modelloEdit);
    formLayout->addRow(classeAmb, classeAmbEdit);
    formLayout->addRow(annoImm, annoImmEdit);
    formLayout->addRow(potenza, potenzaEdit);
    formLayout->addRow(peso, pesoEdit);
    formLayout->addRow(numeroAs, numeroAsEdit);
    formLayout->addRow(automobileCheckbox);
    formLayout->addRow(autotrenoCheckbox);
    formLayout->addRow(autocarroCheckbox);
    formLayout->addRow(esoneroCheckbox);



    mainLayout->addLayout(formLayout);
    QVBoxLayout *verticalLayout = new QVBoxLayout();
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

    //parte connect

    //connect(annullaButton, SIGNAL(clicked()), this, SLOT(close()));
    //connect(salvaButton, SIGNAL(clicked()), this, SLOT(confirm()));

}

void addVeicoli::azzeraRighe() {
    marcaEdit->setText("");
    modelloEdit->setText("");
    classeAmbEdit->setText("");
    annoImmEdit->setDate(QDate::currentDate());
    potenzaEdit->setText("");
    pesoEdit->setText("");
    numeroAsEdit->setText("");
    automobileCheckbox->setChecked(false);
    autotrenoCheckbox->setChecked(false);
    autocarroCheckbox->setChecked(false);
    esoneroCheckbox->setChecked(false);

}

void addVeicoli::mostraErroreInput(string motivo){
    QMessageBox erroreInput;
    if(motivo=="mancaLineEdit")
    erroreInput.critical(this,"Errore","Compilare i campi obbligatori (*) per poter procedere");
    else if (motivo=="mancaCheckBox")
        erroreInput.critical(this,"Errore","Selezionare il tipo di veicolo");

}

void addVeicoli::veicoloAggiunto(){
    QMessageBox veicoloAggiuntoBox;
    veicoloAggiuntoBox.information(this,"Veicolo aggiunto","Il veicolo è stato aggiunto con successo!");
}

void addVeicoli:: conferma(){
    if
            (marcaEdit->text()=="" || modelloEdit->text()=="" || classeAmbEdit->text()==""|| annoImmEdit->text()==""|| potenzaEdit->text()==""|| pesoEdit->text()==""|| numeroAsEdit->text()==""){
        emit erroreInput("mancaLineEdit");   
    }
    else if (!automobileCheckbox->isChecked()&& !autocarroCheckbox->isChecked()&& !autotrenoCheckbox->isChecked()){
        emit erroreInput("mancaCheckBox");
    }
    else
    {
        QStringList *tmp= new QStringList();
        tmp->push_back(marcaEdit->text());
        tmp->push_back(modelloEdit->text());
        tmp->push_back(classeAmbEdit->text());
        tmp->push_back(annoImmEdit->date().toString());
        tmp->push_back(potenzaEdit->text());
        tmp->push_back(pesoEdit->text());
        tmp->push_back(numeroAsEdit->text());
        tmp->push_back(automobileCheckbox->isChecked()? "true":"false");
        tmp->push_back(autocarroCheckbox->isChecked()? "true":"false");
        tmp->push_back(autotrenoCheckbox->isChecked()? "true":"false");
        tmp->push_back(esoneroCheckbox->isChecked()? "true":"false");

        emit inviaStringaVeicoli(*tmp);
        this->close();

        veicoloAggiunto();
    }
}




