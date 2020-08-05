#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "addveicoli.h"
#include "mainwindow.h"

using std::ofstream;
using std::endl;

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(QObject * parent = nullptr);
    ~Controller();
public slots:
    void openAddView() const;

private:
    MainWindow *view;
    addVeicoli *addVeicoliW;

};

#endif // CONTROLLER_H
