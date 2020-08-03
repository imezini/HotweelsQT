#ifndef AUTOVEICOLO_H
#define AUTOVEICOLO_H
#include<QDate>
#include <string>
using std::string;

class autoveicolo {
private:
    string marca;
    string modello;
    string classeambientale;
    QDate annoImmatricolazione;
    int potenza;
    int peso;
    int numeroAssi;


public:
    autoveicolo(string = "", string = "",  string = "", int = 1900, int = 1, int = 1, int = 0, int = 0, int = 0);
    ~autoveicolo() = default;
    string getMarca() const;
    string getModello() const;
    string getClasseambientale() const;
    QDate getData() const;
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    int getPotenza() const;
    int getPeso() const;
    int getNumeroAssi() const;
};

#endif // AUTOVEICOLO_H
