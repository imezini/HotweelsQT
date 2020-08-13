#include "model.h"

Model::Model() : datiTotali(new Container<autoveicolo>()) {

}

void Model::addInList(const QStringList v) {
    autoveicolo* veicolo;
    QDate annoImm = QDate::fromString(v.at(4));
    if(v.at(8) == "true")
       veicolo = new automobile(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(),stoi(v.at(4).toStdString()), stoi(v.at(5).toStdString()), stoi(v.at(6).toStdString()), stoi(v.at(7).toStdString()));

    datiTotali->addInOrder(*veicolo);

}
