#include "autotreno.h"


autotreno::autotreno(string v, string t, string ma, string mod, int y, int m, int d, bool e, int p, int a) : autoveicolo(v,t, ma, mod, y, m, d, e), portata(p), numeroAssi(a) {}

autotreno *autotreno::clone() const {
    return new autotreno(*this);
}

double autotreno::calcolaBollo() const {
    double bollo = (0.0);
    if(getEsonero())
        return bollo;
    else {
        if(numeroAssi == 2){
            if(12 <= portata && portata < 15)
                bollo = 263.50;
            else //if(portata > 15)
                bollo = 364.16;
        }
        else if(numeroAssi == 3){
            if(15 <= portata && portata < 21)
                bollo = 292.30;
            else if(21 <= portata && portata < 23)
                    bollo = 324.50;
                else //if(portata > 23)
                    bollo = 415.60;
        }
        else { //if (numeroAssi >= 4)
            if(23 <= portata && portata < 27)
                bollo = 324.50;
            else if(27 <= portata && portata < 29)
                bollo = 465.13;
                else //if (portata > 29)
                    bollo = 593.50;
        }
    }
    return bollo;
}

int autotreno::getPortata() {
    return portata;
}

int autotreno::getNumeroAssi() {
    return numeroAssi;
}
