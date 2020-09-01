#ifndef AUTOTRENO_H
#define AUTOTRENO_H

#include "autoveicolo.h"

class autotreno: virtual public autoveicolo  {

private:
    int portata;
    int numeroAssi;

public:
    autotreno(string= "", string ="", string = "", string = "", int = 1900, int = 1, int = 1,bool =false, int = 0, int = 0);
    autotreno* clone() const override;
    double calcolaBollo() const;
    int getPortata();
    int getNumeroAssi();
};

#endif // AUTOTRENO_H

