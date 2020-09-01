#ifndef AUTOCARROPLUS_H
#define AUTOCARROPLUS_H

#include "autocarro.h"
#include "automobile.h"

class autocarroplus : public automobile, public autocarro {
public:

    autocarroplus(string = "", string ="", string = "", string = "", int = 1900, int = 1, int = 1,bool = false, string = "", int = 0, int = 0);
    autocarroplus*clone() const override;
    double calcolaBollo() const;
};

#endif // AUTOCARROPLUS_H
