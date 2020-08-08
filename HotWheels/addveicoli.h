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
#include <QDate>
#include <QDateEdit>
#include <QFormLayout>
#include <QMessageBox>
#include <QCheckBox>
#include <QStringList>



using std::string;

class addVeicoli : public QWidget {
        Q_OBJECT
public:
    addVeicoli(QWidget *parent = nullptr);
    void mostraErroreInput(string);
    void veicoloAggiunto();

public slots:
    void azzeraRighe();
    virtual void conferma();


signals:
    void erroreInput(string);
    void inviaStringaVeicoli(const QStringList);


protected:
    QVBoxLayout *verticalLayout;
    QHBoxLayout* mainLayout,*bottoni;
    QLineEdit *marcaEdit, *modelloEdit, *classeAmbEdit, *potenzaEdit, *pesoEdit, *numeroAsEdit;
    QDateEdit *annoImmEdit;
    QPushButton *salvaButton,*annullaButton;
    QCheckBox* automobileCheckbox,*autotrenoCheckbox,*autocarroCheckbox,*esoneroCheckbox;

};

#endif // ADDVEICOLI_H
