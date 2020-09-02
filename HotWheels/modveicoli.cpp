#include "modveicoli.h"

modVeicoli::modVeicoli(QWidget *parent):addVeicoli(parent){
    setMinimumSize(500,400);
    setWindowTitle("Modifica il veicolo selezionato");
}

void modVeicoli::aggiungiDati(const QStringList& c, const unsigned int i){
    ini = i;
    tipoVeicoloBox->setCurrentText(c.at(0));
    targaEdit->setText(c.at(1));
    marcaEdit->setText(c.at(2));
    modelloEdit->setText(c.at(3));
    annoImmEdit->setDate(QDate::fromString(c.at(4)));
    classeAmbBox->setCurrentText(c.at(5));
    potenzaEdit->setValue((c.at(6)).split(" ")[0].toInt());
    portataEdit->setValue((c.at(7)).split(" ")[0].toInt());
    numeroAsEdit->setValue((c.at(8)).split(" ")[0].toInt());
    esoneroCheckbox->setChecked(c.at(9)=="true"? true : false);

}

void modVeicoli:: veicoloModificato(){
    QMessageBox veicoloModificatoBox;
    veicoloModificatoBox.information(this, "Veicolo modificato", "Veicolo modificato con successo");
}

void modVeicoli::conferma(){
    if (targaEdit->text()=="" || marcaEdit->text()==""|| modelloEdit->text()==""|| classeAmbBox->currentIndex()== 0|| annoImmEdit->text()==""|| potenzaEdit->text()==""|| portataEdit->text()==""|| numeroAsEdit->text()==""){
        emit mostraErroreInput("mancaLineEdit");
    }
    else {
        QStringList *tmp= new QStringList();
        tmp->push_back(targaEdit->text());
        tmp->push_back(marcaEdit->text());
        tmp->push_back(modelloEdit->text());
       // tmp->push_back(classeAmbEdit->text());
        tmp->push_back(annoImmEdit->date().toString());
        tmp->push_back(potenzaEdit->text());
        tmp->push_back(portataEdit->text());
        tmp->push_back(numeroAsEdit->text());
        tmp->push_back(esoneroCheckbox->isChecked()? "true":"false");

        emit sostituisciVeicolo(ini, *tmp);
        this->close();

        veicoloModificato();
    }
}


