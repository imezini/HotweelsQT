#ifndef AUTOCARRO_H
#define AUTOCARRO_H

#include "autoveicolo.h"

class autocarro: public autoveicolo {

private:
    int portata;

public:
    autocarro(string ="", string = "", string = "", int = 1900, int = 1, int = 1, int = 0);
    autocarro* clone() const override;
    int getPortata();
};

#endif // AUTOCARRO_H
