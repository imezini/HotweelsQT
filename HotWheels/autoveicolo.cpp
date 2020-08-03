#include "autoveicolo.h"

autoveicolo::autoveicolo(string ma, string mod, string c, int y, int m, int d, int p, int pe, int a) :
    marca(ma), modello(mod), classeambientale(c), annoImmatricolazione(y,m,d), potenza(p), peso(pe), numeroAssi(a) {}

int autoveicolo::getPotenza() const { return potenza; }

string autoveicolo::getClasseambientale() const { return classeambientale; }
