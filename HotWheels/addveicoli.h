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
#include <QComboBox>
#include <QGroupBox>
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
    void sblocca(int) const;

signals:
    void erroreInput(string);
    void inviaStringaVeicoli(const QStringList);

protected:

    QLabel *tipoVeicolo, *targa, *marca, *modello, *annoImm, *classeAmbientale, *potenza, *portata, *numeroAs;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *mainLayout,*bottoni;
    QComboBox *classeAmbBox, *tipoVeicoloBox;
    QLineEdit *targaEdit, *marcaEdit, *modelloEdit, *potenzaEdit, *portataEdit, *numeroAsEdit;
    QDateEdit *annoImmEdit;
    QPushButton *salvaButton,*annullaButton;
    QCheckBox *esoneroCheckbox;
};

#endif // ADDVEICOLI_H
