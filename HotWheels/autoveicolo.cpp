#include "autoveicolo.h"


autoveicolo::autoveicolo(string t, string ma, string mod, string c, int y, int m, int d, int p, int pe, int a, double b) :
    targa(t), marca(ma), modello(mod), classeambientale(c), annoImmatricolazione(y,m,d), potenza(p), peso(pe), numeroAssi(a), bollo(b) {}

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

string autoveicolo::getClasseambientale() const {
    return classeambientale;
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

int autoveicolo::getPotenza() const {
    return potenza;
}

int autoveicolo::getPeso() const {
    return peso;
}

int autoveicolo::getNumeroAssi() const {
    return numeroAssi;
}

