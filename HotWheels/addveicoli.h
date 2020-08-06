#ifndef ADDVEICOLI_H
#define ADDVEICOLI_H

#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QFormLayout>


using std::string;

class addVeicoli : public QDialog {
        Q_OBJECT
public:
    addVeicoli(QWidget *parent = nullptr);

public slots:
    void azzeraRighe();

protected:
    QHBoxLayout *mainLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *marcaEdit, *modelloEdit, *classeAmbEdit;


};

#endif // ADDVEICOLI_H
