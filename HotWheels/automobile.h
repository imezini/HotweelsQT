#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "autoveicolo.h"

class automobile: virtual public autoveicolo

{
public:
    automobile(string ="", string = "", string = "",  string = "", int = 1900, int = 1, int = 1, int = 0, int = 0, int = 0);

};

#endif // AUTOMOBILE_H
