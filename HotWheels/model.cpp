#include "model.h"

Model::Model() : datiTotali(new Container<pointer<autoveicolo>>()), datiFiltrati(new Container<pointer<autoveicolo>>()), modificato(false) {
}




QList<QStringList> Model::getListaVeicoli() {

    QList<QStringList> tot;
    QStringList* riga = new QStringList();

    auto it = datiTotali->begin();
    int i = 0;
    if(!datiTotali->isEmpty()){

        while(it != datiTotali->end()){
            pointer<autoveicolo> autoveicoloTmp = datiTotali->prendiNodoIndice(i);
            if(QString::fromStdString((*(*it)).getTipoVeicolo()) == "Automobile") {
                auto automobileTmp = dynamic_cast<automobile*>(&(*(autoveicoloTmp)));
                riga->push_back(QString::fromStdString(automobileTmp->getTipoVeicolo()));
                riga->push_back(QString::fromStdString(automobileTmp->getTarga()));
                riga->push_back(QString::fromStdString(automobileTmp->getMarca()));
                riga->push_back(QString::fromStdString(automobileTmp->getModello()));
                riga->push_back(automobileTmp->getAnnoImm().toString("dd.MM.yyyy"));
                riga->push_back(QString::fromStdString(automobileTmp->getClasseAmbientale()));
                riga->push_back(QString::number(automobileTmp->getPotenza()));
                riga->push_back("//");
                riga->push_back("//");
                riga->push_back(automobileTmp->getEsonero() ? "SI" : "NO");
                //aggiungere anchE BOLLO in tutti
                tot.push_back(*riga);
                riga->clear();
                i++;
            }
            else if(QString::fromStdString((*(*it)).getTipoVeicolo()) == "Autocarro < 12 tonnellate"){
                auto autocarroTmp = dynamic_cast<autocarro*>(&(*(autoveicoloTmp)));
                riga->push_back(QString::fromStdString(autocarroTmp->getTipoVeicolo()));
                riga->push_back(QString::fromStdString(autocarroTmp->getTarga()));
                riga->push_back(QString::fromStdString(autocarroTmp->getMarca()));
                riga->push_back(QString::fromStdString(autocarroTmp->getModello()));
                riga->push_back(autocarroTmp->getAnnoImm().toString("dd.MM.yyyy"));
                riga->push_back("//");
                riga->push_back("//");
                riga->push_back(QString::number(autocarroTmp->getPortata()));
                riga->push_back("//");
                riga->push_back(autocarroTmp->getEsonero() ? "SI" : "NO");
                tot.push_back(*riga);
                riga->clear();
                i++;
            }
            else{
                auto autotrenoTmp = dynamic_cast<autotreno*>(&(*(autoveicoloTmp)));
                riga->push_back(QString::fromStdString(autotrenoTmp->getTipoVeicolo()));
                riga->push_back(QString::fromStdString(autotrenoTmp->getTarga()));
                riga->push_back(QString::fromStdString(autotrenoTmp->getMarca()));
                riga->push_back(QString::fromStdString(autotrenoTmp->getModello()));
                riga->push_back(autotrenoTmp->getAnnoImm().toString("dd.MM.yyyy"));
                riga->push_back("//");
                riga->push_back("//");
                riga->push_back(QString::number(autotrenoTmp->getPortata()));
                riga->push_back(QString::number(autotrenoTmp->getNumeroAssi()));
                riga->push_back(autotrenoTmp->getEsonero() ? "SI" : "NO");
                tot.push_back(*riga);
                riga->clear();
                i++;
            }
                ++it;
        }
    }
    return tot;
}


void Model::addInList(const QStringList v) {
    pointer<autoveicolo> autoveicolo;
    QDate annoImm = QDate::fromString(v.at(4));
    if(v.at(0) == "Automobile"){
        autoveicolo = new automobile(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(), v.at(9) == "true" ? true : false , v.at(5).toStdString(), stoi(v.at(6).toStdString()));
    }
    else if(v.at(0) == "Autocarro < 12 tonnellate"){
        autoveicolo = new autocarro(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(),v.at(9) == "true" ? true : false , stoi(v.at(7).toStdString()));
    } else
        autoveicolo = new autotreno(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(),v.at(9) == "true" ? true : false , stoi(v.at(7).toStdString()), stoi(v.at(8).toStdString()));

    datiTotali->addInOrder(autoveicolo);
    emit veicoloInLista();
}
