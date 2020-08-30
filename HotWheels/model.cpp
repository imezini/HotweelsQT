#include "model.h"

Model::Model() : datiTotali(new Container<pointer<autoveicolo>>()), datiFiltrati(new Container<pointer<autoveicolo>>()), modificato(false) {
    resetFiltro();
}

Model::~Model()
{
    datiTotali->clear();
    datiFiltrati->clear();
    delete datiTotali;
    delete datiFiltrati;
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


void Model::resetFiltro()
{
    emit resetColoreFiltro();
    datiFiltrati->clear();
    for(auto it=datiTotali->begin();it!=datiTotali->end();++it){
        datiFiltrati->addInOrder(*it);
    }
}

QStringList Model::getListaVeicoliFiltrata(const QString v, QMap<unsigned int, unsigned int> &) const
{
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

//QStringList Model::getListaClientiPDF() const
//{
//    QStringList ret;
//       QString datiCliente;
//       for(auto it=datiTotali->begin();it!=datiTotali->end() && !datiTotali->isEmpty();++it)
//       {
//           datiCliente =(QString::fromStdString(("N:" +(*(*it)).getTarga() + " ,C: " + (*(*it)).getMarca()+ " ,CF: " + (*(*it)).getModello())));
//           ret.push_back(datiCliente);

//}
//    return ret;
//}
//void Model::fltrAutomobile()
//{
//    datiFiltrati->clear();
//    for(auto it= datiTotali->begin(); it!=datiTotali->end(); ++it){
//        veicolo* veicolo = *it;
//        if(dynamic_cast<automobile*>(veicolo) != nullptr){
//            datiFiltrati->addInOrder(*it);
//        }
//    }
//}

//void Model::fltrAutocarro()
//{
//    datiFiltrati->clear();
//    for(auto it= datiTotali->begin(); it!=datiTotali->end(); ++it){
//        veicolo* veicolo = *it;
//        if(dynamic_cast<autocarro*>(veicolo) != nullptr){
//            datiFiltrati->addInOrder(*it);
//        }
//    }
//}

//void Model::fltrAutotreno()
//{
//    datiFiltrati->clear();
//    for(auto it= datiTotali->begin(); it!=datiTotali->end(); ++it){
//        veicolo* veicolo = *it;
//        if(dynamic_cast<autotreno*>(veicolo) != nullptr){
//            datiFiltrati->addInOrder(*it);
//        }
//    }
//}

//void Model::fltrMaxAssi()
//{
//    datiFiltrati->clear();
//    for(auto it= datiTotali->begin(); it!=datiTotali->end(); ++it){
//        veicolo* veicolo = *it;
//        if(dynamic_cast<MaxAssi*>(veicolo) != nullptr){
//            datiFiltrati->addInOrder(*it);
//        }
//    }
//}

//void Model::fltrMinAssi()
//{
//    datiFiltrati->clear();
//    for(auto it= datiTotali->begin(); it!=datiTotali->end(); ++it){
//        veicolo* veicolo = *it;
//        if(dynamic_cast<MinAssi*>(veicolo) != nullptr){
//            datiFiltrati->addInOrder(*it);
//        }
//    }
//}

//void Model::fltrEsonero()
//{
//    datiFiltrati->clear();
//    for(auto it= datiTotali->begin(); it!=datiTotali->end(); ++it){
//        veicolo* veicolo = *it;
//        if(dynamic_cast<Esonero*>(veicolo) != nullptr){
//            datiFiltrati->addInOrder(*it);
//        }
//    }
//}



QList<QStringList> Model::getListaVeicoli() {

    QList<QStringList> tot;
    QStringList* riga = new QStringList();

    auto it = datiTotali->begin();
    if(!datiTotali->isEmpty()){
        while(it != datiTotali->end()){
                riga->push_back(QString::fromStdString((*(*it)).getTipoVeicolo()));
                riga->push_back(QString::fromStdString((*(*it)).getTarga()));
                riga->push_back(QString::fromStdString((*(*it)).getModello()));
                tot.push_back(*riga);
                riga->clear();
                ++it;
            }
        }
     return tot;
}





void Model::addInList(const QStringList v) {
    pointer<autoveicolo> autoveicolo;
    QDate annoImm = QDate::fromString(v.at(4));
    if(v.at(0) == "Automobile"){
        autoveicolo = new automobile(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(),v.at(5) == "true" ? true : false ,v.at(6).toStdString(), stoi(v.at(7).toStdString()));
    }
    else if(v.at(0) == "Autocarro < 12 tonnellate"){
        autoveicolo = new autocarro(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(), v.at(5) == "true" ? true : false, stoi(v.at(8).toStdString()));
    } else
        autoveicolo = new autotreno(v.at(0).toStdString(), v.at(1).toStdString(), v.at(2).toStdString(), v.at(3).toStdString(), annoImm.year(), annoImm.month(), annoImm.day(), v.at(5) == "true" ? true : false,stoi(v.at(8).toStdString()), stoi(v.at(9).toStdString()));

    datiTotali->addInOrder(autoveicolo);
    emit veicoloInLista();
}
