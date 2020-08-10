#ifndef MODIFICAVEICOLI_H
#define MODIFICAVEICOLI_H

#include "addveicoli.h"


class modificaveicoli : public addVeicoli
{
    Q_OBJECT
private:

    unsigned int ini;

public:
    explicit modificaveicoli(QWidget *parent = nullptr);

    void aggiungiDati(const QStringList &, const unsigned int);

    void veicoloModificato();

public slots:

    void conferma() override;

signals:

    void sostituisciVeicolo(const unsigned int, const QStringList);
};

#endif // MODIFICAVEICOLI_H
