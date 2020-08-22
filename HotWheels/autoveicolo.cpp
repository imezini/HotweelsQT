#include "autoveicolo.h"


autoveicolo::autoveicolo(string t, string ma, string mod, int y, int m, int d) :
    targa(t), marca(ma), modello(mod), annoImmatricolazione(y,m,d) {}


bool autoveicolo::operator==(const autoveicolo &a) const {
    return targa == a.getTarga();
}

bool autoveicolo::operator<(const autoveicolo &a) const {
    return targa < a.getTarga();
}

bool autoveicolo::operator>(const autoveicolo &a) const {
    return targa > a.getTarga();
}

string autoveicolo::getTarga() const {
    return targa;
}

string autoveicolo::getMarca() const {
    return marca;
}

string autoveicolo::getModello() const {
    return modello;
}


QDate autoveicolo::getAnnoImm() const {
    return annoImmatricolazione;
}

int autoveicolo::getGiorno() const {
    return annoImmatricolazione.QDate::day();
}

int autoveicolo::getMese() const {
    return annoImmatricolazione.QDate::month();
}

int autoveicolo::getAnno() const {
    return annoImmatricolazione.QDate::year();
}

