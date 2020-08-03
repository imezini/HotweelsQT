#include "autoveicolo.h"

autoveicolo::autoveicolo(int p, string c): potenza(p),classeambientale(c){}

int autoveicolo::getPotenza() const { return potenza; }

string autoveicolo::getClasseambientale() const { return classeambientale; }
