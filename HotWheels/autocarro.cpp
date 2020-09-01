#include "autocarro.h"

autocarro::autocarro(string v, string t, string ma, string mod, int y, int m, int d, bool e, int p) : autoveicolo(v, t, ma, mod, y, m, d, e), portata(p) {}

autocarro *autocarro::clone() const {
    return new autocarro(*this);
}

double autocarro::calcolaBollo() const {
    double bollo;
    if(getEsonero())
        bollo = (0.0);
    else{
        if(1 <= portata && portata < 4)
            bollo = 25.10;
        else if(4 <= portata && portata < 8){
                 bollo = 35.10;
        }else if(8 <= portata && portata < 10){
                 bollo = 45.10;
        }else if( 10 <= portata && portata < 20){
                 bollo = 75.30;
        }else if(20 <= portata && portata < 30){
                 bollo = 122.50;
        }else if(30 <= portata && portata < 50){
                 bollo = 190.10;
        }else if(50 <= portata)
                 bollo = 235.50;
    }
    return bollo;
}

int autocarro::getPortata() {
    return portata;
}
