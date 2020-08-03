#ifndef AUTOCARRO_H
#define AUTOCARRO_H

#include "autoveicolo.h"

class autocarro: virtual public autoveicolo

{
private: int numeroassi;

public:
    autocarro();
};

#endif // AUTOCARRO_H
