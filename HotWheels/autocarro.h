#ifndef AUTOCARRO_H
#define AUTOCARRO_H

#include "autoveicolo.h"

class autocarro: virtual public autoveicolo {

private:
    int portata;

public:
    autocarro(string ="", string ="", string = "", string = "", int = 1900, int = 1, int = 1, bool = false, int = 0);
    autocarro* clone() const override;
    double calcolaBollo() const;
    int getPortata();
};

#endif // AUTOCARRO_H
