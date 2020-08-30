#include "autocarro.h"

autocarro::autocarro(string v, string t, string ma, string mod, int y, int m, int d, bool e, int p) : autoveicolo(v, t, ma, mod, y, m, d, e), portata(p) {}

autocarro *autocarro::clone() const {
    return new autocarro(*this);
}


int autocarro::getPortata() {
    return portata;
}
