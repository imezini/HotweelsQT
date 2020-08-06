#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), view(new MainWindow()),addVeicoliW(new addVeicoli()) {
    connect(view, SIGNAL(openAddVeicoli()), this, SLOT(openAddView()));

}

void Controller::openAddView() const {
    addVeicoliW->show();
}
