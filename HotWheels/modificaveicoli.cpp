#include "modificaveicoli.h"

modificaveicoli::modificaveicoli(QWidget *parent):addVeicoli(parent){
    setMinimumSize(500,400);
    setWindowTitle("Finestra modifica veicolo");
}

void modificaveicoli::aggiungiDati(const QStringList& c, const unsigned int i){

    targaEdit->setText(c.at(0));
    marcaEdit->setText(c.at(1));
    modelloEdit->setText(c.at(2));
    classeAmbEdit->setText(c.at(3));
    annoImmEdit->setDate(QDate::fromString(c.at(4)));
    potenzaEdit->setText(c.at(5));
    pesoEdit->setText(c.at(6));
    numeroAsEdit->setText(c.at(7));
    automobileCheckbox->setChecked(c.at(8)=="true"? true : false);
    autotrenoCheckbox->setChecked(c.at(9)=="true"? true : false);
    autocarroCheckbox->setChecked(c.at(10)=="true"? true : false);
    esoneroCheckbox->setChecked(c.at(11)=="true"? true : false);

}
void modificaveicoli:: veicoloModificato(){
    QMessageBox veicoloModificatoBox;
    veicoloModificatoBox.information(this, "Veicolo modificato", "Veicolo modificato con successo");
}

void modificaveicoli::conferma(){
    if (targaEdit->text()=="" || marcaEdit->text()==""|| modelloEdit->text()==""|| classeAmbEdit->text()==""|| annoImmEdit->text()==""|| potenzaEdit->text()==""|| pesoEdit->text()==""|| numeroAsEdit->text()==""){
        emit mostraErroreInput("mancaLineEdit");
    }
    else if (!automobileCheckbox->isChecked()&& !autocarroCheckbox->isChecked()&& !autotrenoCheckbox->isChecked()){
        emit mostraErroreInput("mancaCheckBox");
    }
    else
{
        QStringList *tmp= new QStringList();
        tmp->push_back(targaEdit->text());
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

