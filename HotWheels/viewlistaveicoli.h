#ifndef VIEWLISTAVEICOLI_H
#define VIEWLISTAVEICOLI_H

#include <QListWidget>

class viewListaVeicoli : public QListWidget {
        Q_OBJECT
public:
    viewListaVeicoli(QWidget* = nullptr);

    unsigned int getIndex() const;

    bool isSomeoneSelected() const;

    void unSelectIndex() const;

};

#endif // VIEWLISTAVEICOLI_H
