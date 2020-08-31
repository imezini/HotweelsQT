#include "autotreno.h"


autotreno::autotreno(string v, string t, string ma, string mod, int y, int m, int d, bool e, int p, int a) : autocarro(v,t, ma, mod, y, m, d, e, p), numeroAssi(a) {}

autotreno *autotreno::clone() const {
    return new autotreno(*this);
}

int autotreno::getNumeroAssi() {
    return numeroAssi;
}
