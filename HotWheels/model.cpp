#include "model.h"

Model::Model() : datiTotali(new Container<pointer<autoveicolo>>()), datiFiltrati(new Container<pointer<autoveicolo>>()), modificato(false) {}

Model::~Model()
{
    datiTotali->clear();
    datiFiltrati->clear();
    delete datiTotali;
    delete datiFiltrati;
}

void Model::addInList(const QStringList v) {
    pointer<autoveicolo> autoveicolo;
    QDate annoImm = QDate::fromString(v.at(4));
    if(v.at(0) == "Automobile"){
        autoveicolo = new automobile(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(), v.at(9) == "true" ? true : false , v.at(5).toStdString(), stoi(v.at(6).toStdString()));
    }
    else if(v.at(0) == "Autocarro < 12 tonnellate"){
        autoveicolo = new autocarro(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(),v.at(9) == "true" ? true : false , stoi(v.at(7).toStdString()));
    }
    else if(v.at(0) == "Autocarro >= 12 tonnellate"){
        autoveicolo = new autotreno(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(),v.at(9) == "true" ? true : false , stoi(v.at(7).toStdString()), stoi(v.at(8).toStdString()));
    }
    else
        autoveicolo= new autocarroplus(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(),v.at(9) == "true" ? true : false , v.at(5).toStdString(), stoi(v.at(6).toStdString()), stoi(v.at(7).toStdString()));

    datiTotali->addInOrder(autoveicolo);
    emit veicoloInLista();
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
                riga->push_back(QString::number(automobileTmp->getPotenza()) + " kw");
                riga->push_back("//");
                riga->push_back("//");
                riga->push_back(automobileTmp->getEsonero() ? "SI" : "NO");
                riga->push_back(QString::number(automobileTmp->calcolaBollo(), 'f', 2) + " €");
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
                riga->push_back(QString::number(autocarroTmp->getPortata()) + " t");
                riga->push_back("//");
                riga->push_back(autocarroTmp->getEsonero() ? "SI" : "NO");
                riga->push_back(QString::number(autocarroTmp->calcolaBollo(), 'f', 2) + " €");
                tot.push_back(*riga);
                riga->clear();
                i++;
            }
            else if(QString::fromStdString((*(*it)).getTipoVeicolo()) == "Autocarro >= 12 tonnellate"){
                auto autotrenoTmp = dynamic_cast<autotreno*>(&(*(autoveicoloTmp)));
                riga->push_back(QString::fromStdString(autotrenoTmp->getTipoVeicolo()));
                riga->push_back(QString::fromStdString(autotrenoTmp->getTarga()));
                riga->push_back(QString::fromStdString(autotrenoTmp->getMarca()));
                riga->push_back(QString::fromStdString(autotrenoTmp->getModello()));
                riga->push_back(autotrenoTmp->getAnnoImm().toString("dd.MM.yyyy"));
                riga->push_back("//");
                riga->push_back("//");
                riga->push_back(QString::number(autotrenoTmp->getPortata()) + " t");
                riga->push_back(QString::number(autotrenoTmp->getNumeroAssi()));
                riga->push_back(autotrenoTmp->getEsonero() ? "SI" : "NO");
                riga->push_back(QString::number(autotrenoTmp->calcolaBollo(), 'f', 2) + " €");
                tot.push_back(*riga);
                riga->clear();
                i++;
            }
            else if(QString::fromStdString((*(*it)).getTipoVeicolo()) == "Autocarro tipo C") {
                auto autocarroplusTmp = dynamic_cast<autocarroplus*>(&(*(autoveicoloTmp)));
                riga->push_back(QString::fromStdString(autocarroplusTmp->getTipoVeicolo()));
                riga->push_back(QString::fromStdString(autocarroplusTmp->getTarga()));
                riga->push_back(QString::fromStdString(autocarroplusTmp->getMarca()));
                riga->push_back(QString::fromStdString(autocarroplusTmp->getModello()));
                riga->push_back(autocarroplusTmp->getAnnoImm().toString("dd.MM.yyyy"));
                riga->push_back(QString::fromStdString(autocarroplusTmp->getClasseAmbientale()));
                riga->push_back(QString::number(autocarroplusTmp->getPotenza()) + " kw");
                riga->push_back(QString::number(autocarroplusTmp->getPortata()) + " t");
                riga->push_back("//");
                riga->push_back(autocarroplusTmp->getEsonero() ? "SI" : "NO");
                riga->push_back(QString::number(autocarroplusTmp->calcolaBollo(), 'f', 2) + " €");
                tot.push_back(*riga);
                riga->clear();
                i++;
            }
                ++it;
        }
    }
    return tot;
}


//QStringList Model::getListaVeicoli(QMap<int, int>& indexMapper) const
//{
//    QStringList tot;
//    QString singolo;
//    auto it=datiTotali->begin();
//    int count=0;
//    if(!datiTotali->empty()){
//        while(it!=datiTotali->end()){
//            singolo = (QString::fromStdString((*(*it)).getTarga() + " " + (*(*it)).getModello()));
//            indexMapper.insert((int)tot.count(),count);
//            tot.push_back(singolo);
//            count++;
//            ++it;
//        }
//    }
//    return ret;
//}

void Model::elimina(const int i) {
    modificato=true;
    datiTotali->rimuoviIndice(i);
}


QStringList Model::getListaVeicoliFiltrata(const QString v, QMap<unsigned int, unsigned int> &) const {
    QStringList ret;
    QString autoveicolo;
    QRegExp regex(v,Qt::CaseInsensitive, QRegExp::Wildcard);
    auto it=datiFiltrati->begin();
    unsigned int count=0;
    if(!datiFiltrati->isEmpty()){
        if(v.at(0) == "Automobile"){
           autoveicolo = (QString::fromStdString((*(*it)).getTarga()));
            if(autoveicolo.contains(regex)){
                //indexMapper.insert((uint)ret.count(),count);

                ret.push_back(autoveicolo);
            }
            count++;
            ++it;
        }
    }

    return ret;

}

