#ifndef AUTOVEICOLO_H
#define AUTOVEICOLO_H
#include<QDate>
#include <string>
using std::string;

class autoveicolo {
private:
    string targa;
    string marca;
    string modello;
    string classeambientale;
    QDate annoImmatricolazione;
    int potenza;
    int peso;
    int numeroAssi;



public:
    autoveicolo(string ="", string = "", string = "",  string = "", int = 1900, int = 1, int = 1, int = 0, int = 0, int = 0);
    ~autoveicolo() = default;

    virtual bool operator==(const autoveicolo&) const;

    int calcolaBollo(const int&);

    string getTarga() const;
    string getMarca() const;
    string getModello() const;
    string getClasseambientale() const;
    QDate getAnnoImm() const;
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    int getPotenza() const;
    int getPeso() const;
    int getNumeroAssi() const;
};

#endif // AUTOVEICOLO_H
