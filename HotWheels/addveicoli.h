#ifndef ADDVEICOLI_H
#define ADDVEICOLI_H

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QWidget>
#include <QFormLayout>


using std::string;

class addVeicoli : public QWidget {
        Q_OBJECT
private:
//    QHBoxLayout *mainLayout;
//    QVBoxLayout *verticalLayout;
    QLineEdit *marcaEdit, *modelloEdit, *classeAmbEdit;

public:
    addVeicoli(QWidget *parent = nullptr);

public slots:
    void azzeraRighe();


};

#endif // ADDVEICOLI_H
