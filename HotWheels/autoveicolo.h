#ifndef AUTOVEICOLO_H
#define AUTOVEICOLO_H
#include<QDate>
#include <string>
using std::string;

class autoveicolo {
private:
    string marca;
    string modello;
    QDate annoImmatricolazione;
    int potenza;
    string classeambientale;
    int peso;
    int numeroAssi;


public:
    autoveicolo(int = 0, string = "");
    ~autoveicolo() = default;
    string getMarca() const;
    string getModello() const;
    QDate getData() const;
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    int getPotenza() const;
    string getClasseambientale() const;
    int getPeso() const;
    int getNumeroAssi() const;
};

#endif // AUTOVEICOLO_H
