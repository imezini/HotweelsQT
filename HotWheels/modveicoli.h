#ifndef MODVEICOLI_H
#define MODVEICOLI_H

#include "addveicoli.h"


class modVeicoli : public addVeicoli
{
    Q_OBJECT
private:

    unsigned int ini;

public:
    explicit modVeicoli(QWidget *parent = nullptr);

    void aggiungiDati(const QStringList &, const unsigned int);

    void veicoloModificato();

public slots:

    void conferma() override;

signals:

    void sostituisciVeicolo(const unsigned int, const QStringList);
};

#endif // MODVEICOLI_H
