#include "autoveicolo.h"

autoveicolo::autoveicolo(int p, string c): potenza(p),classeambientale(c){}

autoveicolo::getPotenza() { return potenza; }

autoveicolo::getClasseambientale() { return classeambientale; }
