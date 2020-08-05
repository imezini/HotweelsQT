#ifndef ADDVEICOLI_H
#define ADDVEICOLI_H

#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

using std::string;

class addVeicoli : public QDialog {
        Q_OBJECT
public:
    addVeicoli(QWidget *parent = nullptr);
private:
    QHBoxLayout *mainLayout;
    QLineEdit *marcaEdit, *modelloEdit, *classeAmbEdit;

};

#endif // ADDVEICOLI_H
