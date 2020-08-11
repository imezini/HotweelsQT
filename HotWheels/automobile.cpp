#include "automobile.h"



automobile::automobile(string t, string ma, string mo,  string ca, int y, int m, int d, int po, int pe, int na) : autoveicolo(t, ma, mo, ca, y, m, d, po, pe, na) {}

double automobile::calcolaBollo(const automobile& a) const {
    int x = a.getPotenza();
    double costo;
    if(a.getClasseambientale() == "Euro 4" || a.getClasseambientale() == "Euro 5" || a.getClasseambientale() == "Euro 6") {
        if(x < 100)
            costo = (x * 2,58);
        else
            costo = ((100 * 2,58) + ((x-100) * 3,87));
    }
    else {
        if(a.getClasseambientale() == "Euro 0"){
            if(x < 100)
                costo =  (x * 3);
            else
                costo = ((100 * 3) + ((x-100) * 4,5));
        }
        else {
            if(a.getClasseambientale() == "Euro 1"){
                if(x < 100)
                    costo = (x * 2,9);
                else
                    costo = ((100 * 2,9) + ((x-100) * 4,35));
            }
            else {
                if(a.getClasseambientale() == "Euro 2") {
                    if(x < 100)
                        costo = (x * 2,8);
                    else
                        costo = ((100 * 2,8) + ((x-100) * 4,2));
                }
                else {
                    if(a.getClasseambientale() == "Euro 3") {
                        if(x < 100)
                            costo =  (x * 2,7);
                        else
                            costo = ((100 * 2,7) + ((x-100) * 4,05));
                    }
                }
            }
        }
    }
    return costo;
}
