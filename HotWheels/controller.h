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
    void updateVeicoliTable();
    //void openAddView()const;
    //void erroreInputRicevuto(string);
    void filtraTuttiVeicolo();
    void filtraTuttiAutomobile();
    void filtraTuttiAutocarro();
    void filtraTuttiAutotreno();
    void filtraTuttiVeicoloMaxAssi();
    void filtraTuttiVeicoloMinAssi();
    void filtraTuttiVeicoloEsonero();
    void resetTuttiColoreFiltro() const;
//    void esportaPDFClienti()const;

private:
    MainWindow *view;
    Model *m;
    // QMap<unsigned int,unsigned int> indexTranslate;

};

#endif // CONTROLLER_H
