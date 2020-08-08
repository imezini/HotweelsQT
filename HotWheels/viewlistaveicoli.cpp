#include "viewlistaveicoli.h"

viewListaVeicoli::viewListaVeicoli(QWidget *parent) : QListWidget(parent) {}

unsigned int viewListaVeicoli::getIndex()const{
    return (unsigned int)this->selectedIndexes()[0].row();
}

bool viewListaVeicoli::isSomeoneSelected() const
{
    return !this->selectedIndexes().empty();
}

void viewListaVeicoli::unSelectIndex() const
{
    this->selectedIndexes().clear();
}
