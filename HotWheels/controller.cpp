#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent),view(new MainWindow()), m(new Model()), addVeicoliW(new addVeicoli()) {

    connect(addVeicoliW, SIGNAL(inviaStringaVeicoli(const QStringList)), this, SLOT(addVeicoloCont(const QStringList)));
    connect(m, SIGNAL(veicoloInLista()), this, SLOT(updateVeicoliTable()));

}

Controller::~Controller() {

}

void Controller::addVeicoloCont(const QStringList v) {
        m->addInList(v);
}

void Controller::updateVeicoliTable() {
    view->mostraVeicoli(m->getListaVeicoli());
}
