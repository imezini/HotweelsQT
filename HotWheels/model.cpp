#include "model.h"

Model::Model() : datiTotali(new Container<autoveicolo>()) {

}

void Model::addInList(const QStringList v) {
    autoveicolo* veicolo;
    QDate annoImm = QDate::fromString(v.at(4));
    if(v.at(0) == "Automobile")
       veicolo = new automobile(v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(), v.at(5).toStdString(), stoi(v.at(6).toStdString()));

    datiTotali->addInOrder(*veicolo);


}
