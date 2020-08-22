#include "autocarro.h"

autocarro::autocarro(string t, string ma, string mod, int y, int m, int d, int p) : autoveicolo(t, ma, mod, y, m, d), portata(p) {}


int autocarro::getPortata() {
    return portata;
}
