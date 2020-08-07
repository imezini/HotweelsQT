#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <iostream>
#include <QFileDialog>
#include "addveicoli.h"
#include "mainwindow.h"

using std::ofstream;
using std::endl;

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
public slots:


private:




};

#endif // CONTROLLER_H
