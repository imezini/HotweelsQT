#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <iostream>
#include <QFileDialog>
#include "addveicoli.h"
#include "mainwindow.h"
#include "model.h"

using std::ofstream;
using std::endl;

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
public slots:
    void addVeicoloCont(const QStringList);

private:
    Model* m;
    addVeicoli* addVeicoliW;

};

#endif // CONTROLLER_H
