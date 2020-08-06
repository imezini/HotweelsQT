#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), view(new MainWindow()),addVeicoliW (new addVeicoli()) {
    connect(view, SIGNAL(openAddVeicoli()), this, SLOT(openAddView()));

}

Controller::~Controller() {

}

void Controller::openAddView() const {
    addVeicoliW->azzeraRighe();
    //addVeicoliW->setModal(true);
    addVeicoliW->show();
}
