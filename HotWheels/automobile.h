#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "autoveicolo.h"

class automobile: public autoveicolo {

private:
    string classeAmbientale;
    int potenza;

public:
    automobile(string ="", string = "", string = "", int = 1900, int = 1, int = 1, string = "", int = 0);
    //double calcolaBollo(const automobile&) const;
    automobile* clone() const override;
    string getClasseambientale() const;
    int getPotenza() const;


};

#endif // AUTOMOBILE_H

