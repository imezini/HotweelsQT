#ifndef MODEL_H
#define MODEL_H

#include "pointer.h"
#include "container.h"
#include "autoveicolo.h"
#include "automobile.h"
#include <QString>
#include <QObject>
#include <QDate>
#include <string>

class Model : public QObject {
    Q_OBJECT
public:
    Model();
    QStringList getListaVeicoli();

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
