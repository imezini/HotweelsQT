#ifndef AUTOVEICOLO_H
#define AUTOVEICOLO_H


class autoveicolo
{
    private:
    int potenza;
    string classeambientale;

public:
    autoveicolo(int = 0, string = "");
    ~autoveicolo() = default;
    int getPotenza() const;
    string getClasseambientale() const;
};

#endif // AUTOVEICOLO_H
