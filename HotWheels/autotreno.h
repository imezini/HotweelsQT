#ifndef AUTOTRENO_H
#define AUTOTRENO_H

#include "autocarro.h"

class autotreno: public autocarro  {

private:
    int numeroAssi;

public:
    autotreno(string ="", string = "", string = "", int = 1900, int = 1, int = 1, int = 0, int = 0);
    autotreno* clone() const override;
    int getNumeroAssi();
};

#endif // AUTOTRENO_H

