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

    double bollo;



public:
    autoveicolo(string ="", string = "", string = "",  string = "", int = 1900, int = 1, int = 1, int = 0, int = 0, int = 0, double = 0);
    ~autoveicolo() = default;

    virtual bool operator==(const autoveicolo&) const;

    virtual bool operator<(const autoveicolo&) const;
    virtual bool operator>(const autoveicolo&) const;


    //virtual double calcolaBollo(const autoveicolo&) const = 0; //metodo virtuale puro

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
