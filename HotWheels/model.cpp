#include "model.h"

Model::Model() : datiTotali(new Container<autoveicolo>()) {

}

//QStringList Model::getListaVeicoli() {
//    QString veicolo;
//    QStringList tot;
//    auto it = datiTotali->begin();
//    int count = 0;
//    while(it != datiTotali->end()){
//           veicolo = (QString::fromStdString(*(*it))).getTarga());
//           tot.push_back(veicolo);
//           ++it;
//    }
//    return tot;
//}

void Model::addInList(const QStringList v) {
    autoveicolo* veicolo;
    QDate annoImm = QDate::fromString(v.at(4));
    if(v.at(0) == "Automobile")
       veicolo = new automobile(v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(), v.at(5).toStdString(), stoi(v.at(6).toStdString()));

    datiTotali->addInOrder(*veicolo);
   // emit veicoloInLista();

}
