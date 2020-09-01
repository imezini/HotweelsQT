#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QObject>
#include <QDate>
#include <string>
#include <QList>

#include "pointer.h"
#include "container.h"
#include "autoveicolo.h"
#include "automobile.h"
#include "autocarro.h"
#include "autotreno.h"

class Model : public QObject {
    Q_OBJECT

public:
    Model();
    ~Model();
    QList<QStringList> getListaVeicoli();
    void elimina(const int);
    void resetFiltro();
    QStringList getListaVeicoliFiltrata(const QString,QMap<unsigned int,unsigned int> &) const;

public slots:
    void addInList(const QStringList);

signals:
    void veicoloInLista();

private:

    Container <pointer<autoveicolo>> *datiTotali;
    Container <pointer<autoveicolo>> *datiFiltrati;
    bool modificato;
};

#endif // MODEL_H
