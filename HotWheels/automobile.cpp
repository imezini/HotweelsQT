#include "automobile.h"



automobile::automobile(string v, string t, string ma, string mod, int y, int m, int d, bool e, string cl, int po) : autoveicolo(v, t, ma, mod, y, m, d, e), classeAmbientale(cl), potenza(po){}

automobile *automobile::clone() const {
    return new automobile(*this);
}



string automobile::getClasseAmbientale() const {
    return classeAmbientale;
}

int automobile::getPotenza() const {
    return potenza;
}


double automobile::calcolaBollo() const {

  double bollo;
  if(getEsonero())
      bollo = (0.0);
  else{
      if(classeAmbientale == "Euro 4" || classeAmbientale == "Euro 5" || classeAmbientale == "Euro 6") {
            if(potenza < 100)
                bollo =  potenza * 2.58;
            else
                bollo =  (100 * 2.58) + ((potenza-100) * 3.87);
        }
        else{
            if(classeAmbientale == "Euro 0"){
                if(potenza < 100)
                    bollo =  potenza * 3;
                else
                    bollo =  (100 * 3) + ((potenza-100) * 4.5);
            }
            if(classeAmbientale == "Euro 1"){
                if(potenza < 100)
                    bollo =  potenza * 2.9;
                else
                    bollo =  (100 * 2.9) + ((potenza-100) * 4.35);
            }
            if(classeAmbientale == "Euro 2") {
                if(potenza < 100)
                    bollo =  potenza * 2.8;
                else
                    bollo =  (100 * 2.8) + ((potenza-100) * 4.2);
            }
            if(classeAmbientale == "Euro 3") {
                if(potenza < 100)
                    bollo =  potenza * 2.7;
                else
                    bollo =  (100 * 2.7) + ((potenza-100) * 4.05);
            }
        }
  }
  return bollo;
}

