#include "model.h"

Model::Model() : datiTotali(new Container<pointer<autoveicolo>>()), datiFiltrati(new Container<pointer<autoveicolo>>()), modificato(false) {
}

QStringList Model::getListaVeicoli() {
    QString singolo;
    QStringList tot;
    int i = 0;
    auto it = datiTotali->begin();
    if(!datiTotali->isEmpty()){
        while(it!=datiTotali->end()){
            singolo = (QString::fromStdString((*(*it)).getTarga()));
            tot.push_back(singolo);
            ++it;
        }
    }
    return tot;
}


void Model::addInList(const QStringList v) {
    pointer<autoveicolo> autoveicolo;
    QDate annoImm = QDate::fromString(v.at(4));
    if(v.at(0) == "Automobile"){
       autoveicolo = new automobile(v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(), v.at(5).toStdString(), stoi(v.at(6).toStdString()));
    }
    datiTotali->addInOrder(autoveicolo);
    emit veicoloInLista();
}
