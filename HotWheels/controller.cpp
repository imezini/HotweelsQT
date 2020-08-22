#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), m(new Model()), addVeicoliW(new addVeicoli()) {

    connect(addVeicoliW, SIGNAL(inviaStringaVeicoli(const QStringList)), this, SLOT(addVeicoloCont(const QStringList)));

}

Controller::~Controller() {

}

void Controller::addVeicoloCont(const QStringList v) {
        m->addInList(v);
}

