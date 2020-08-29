#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent),view(new MainWindow()), m(new Model()) {

    connect(m, SIGNAL(veicoloInLista()), this, SLOT(updateVeicoliTable()));
    connect(view->vistaAdd, SIGNAL(inviaStringaVeicoli(const QStringList)), this, SLOT(addVeicoloCont(const QStringList)));

    view->show();
}

Controller::~Controller() {

}

void Controller::addVeicoloCont(const QStringList v) {
        m->addInList(v);
}

void Controller::updateVeicoliTable() {
    view->mostraVeicoli(m->getListaVeicoli());
}
