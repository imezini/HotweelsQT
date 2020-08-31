#include "autotreno.h"


autotreno::autotreno(string v, string t, string ma, string mod, int y, int m, int d, bool e, int p, int a) : autoveicolo(v,t, ma, mod, y, m, d, e), portata(p), numeroAssi(a) {}

autotreno *autotreno::clone() const {
    return new autotreno(*this);
}

int autotreno::getPortata() {
    return portata;
}

int autotreno::getNumeroAssi() {
    return numeroAssi;
}
