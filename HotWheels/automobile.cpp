#include "automobile.h"



automobile::automobile(string v, string t, string ma, string mod, int y, int m, int d, bool e, string cl, int po) : autoveicolo(v, t, ma, mod, y, m, d, e), classeAmbientale(cl), potenza(po){}

automobile *automobile::clone() const {
    return new automobile(*this);
}



string automobile::getClasseambientale() const {
    return classeAmbientale;
}

int automobile::getPotenza() const {
    return potenza;
}


/*
double automobile::calcolaBollo(const automobile& a) const {
    int x = a.getPotenza();
    if(a.getClasseambientale() == "Euro 4" || a.getClasseambientale() == "Euro 5" || a.getClasseambientale() == "Euro 6") {
        if(x < 100)
            return x * 2,58;
        else
            return (100 * 2,58) + ((x-100) * 3,87);
    }
    else{
        if(a.getClasseambientale() == "Euro 0"){
            if(x < 100)
                return x * 3;
            else
                return (100 * 3) + ((x-100) * 4,5);
        }
        if(a.getClasseambientale() == "Euro 1"){
            if(x < 100)
                return x * 2,9;
            else
                return (100 * 2,9) + ((x-100) * 4,35);
        }
        if(a.getClasseambientale() == "Euro 2") {
            if(x < 100)
                return x * 2,8;
            else
                return (100 * 2,8) + ((x-100) * 4,2);
        }
        if(a.getClasseambientale() == "Euro 3") {
            if(x < 100)
                return x * 2,7;
            else
                return (100 * 2,7) + ((x-100) * 4,05);
        }
    }
}
*/

