#ifndef MODEL_H
#define MODEL_H

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
    //QStringList getListaVeicoli();

public slots:
    void addInList(const QStringList);

signals:
    //void veicoloInLista();

private:
    Container<autoveicolo> *datiTotali;
};

#endif // MODEL_H
