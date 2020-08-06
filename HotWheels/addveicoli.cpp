#include "addveicoli.h"

using std::string;

addVeicoli::addVeicoli(QWidget *parent) : QDialog (parent) {

    setWindowTitle("Aggiungi un veicolo");
    mainLayout = new QHBoxLayout(this);

    setLayout(mainLayout);


    QLabel *marca = new QLabel("(*)Marca: ");
    marcaEdit = new QLineEdit();
    marcaEdit->setPlaceholderText("es. Fiat");

    QLabel *modello = new QLabel("(*)Modello: ");
    modelloEdit = new QLineEdit();
    modelloEdit->setPlaceholderText("es. Tipo");

    QLabel *classeAmb = new QLabel("(*)Classe Ambientale: ");
    classeAmbEdit = new QLineEdit();
    classeAmbEdit->setPlaceholderText("Euro 6");

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->addRow(marca, marcaEdit);
    formLayout->addRow(modello, modelloEdit);
    formLayout->addRow(classeAmb, classeAmbEdit);

    mainLayout->addLayout(formLayout);
    verticalLayout = new QVBoxLayout();
    mainLayout->addLayout(verticalLayout);




}

void addVeicoli::azzeraRighe() {
    marcaEdit->setText("");
    modelloEdit->setText("");
    classeAmbEdit->setText("");
}
