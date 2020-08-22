#include "autotreno.h"


autotreno::autotreno(string t, string ma, string mod, int y, int m, int d, int p, int a) : autocarro(t, ma, mod, y, m, d, p), numeroAssi(a) {}

int autotreno::getNumeroAssi() {
    return numeroAssi;
}
