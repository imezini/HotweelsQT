#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "autoveicolo.h"

class automobile: virtual public autoveicolo {

private:
    string classeAmbientale;
    int potenza;

public:
    automobile(string = "", string ="", string = "", string = "", int = 1900, int = 1, int = 1,bool = false, string = "", int = 0);
    virtual double calcolaBollo() const;
    automobile* clone() const override;
    string getClasseAmbientale() const;
    int getPotenza() const;


};

#endif // AUTOMOBILE_H
