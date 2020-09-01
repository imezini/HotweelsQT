#include "autocarroplus.h"

autocarroplus::autocarroplus(string t, string ta, string ma,string mo, int a, int m, int g, bool e, string ca, int po, int p) : automobile(t,ta,ma,mo,a,m,g,e,ca,po), autocarro(t,ta,ma,mo,a,m,g,e,p){}


autocarroplus *autocarroplus::clone() const {
    return new autocarroplus(*this);
}

double autocarroplus::calcolaBollo() const {
    double bollo = (0.0);
    if(getEsonero())
        return bollo;
    else{
        bollo = potenza * portata;
    }
    return bollo;
}

