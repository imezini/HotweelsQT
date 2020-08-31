#ifndef AUTOVEICOLO_H
#define AUTOVEICOLO_H
#include<QDate>
#include <string>
using std::string;

class autoveicolo {
private:
    string tipoVeicolo;
    string targa;
    string marca;
    string modello;
    QDate annoImmatricolazione;
    bool esonero;

    //double bollo;

public:
    autoveicolo(string= "", string ="", string = "", string = "", int = 1900, int = 1, int = 1, bool = false);

    virtual ~autoveicolo() = default;

    virtual bool operator==(const autoveicolo&) const;
    virtual bool operator<(const autoveicolo&) const;
    virtual bool operator>(const autoveicolo&) const;

    virtual autoveicolo* clone() const = 0;

    //virtual double calcolaBollo(const autoveicolo&) const; //metodo virtuale puro

    string getTipoVeicolo() const;
    string getTarga() const;
    string getMarca() const;
    string getModello() const;
    QDate getAnnoImm() const;
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    bool getEsonero() const;

};

#endif // AUTOVEICOLO_H
