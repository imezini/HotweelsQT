#ifndef AUTOTRENO_H
#define AUTOTRENO_H

#include "autoveicolo.h"

class autotreno: virtual public autoveicolo

{
private: int numeroassi;

public:
    autotreno();
};

#endif // AUTOTRENO_H