#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QMenuBar>
#include <QAction>
#include <QAbstractItemView>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QTableWidget>
#include <QSizePolicy>
#include <QString>
#include <QList>

#include "pointer.h"
#include "addveicoli.h"
#include "modveicoli.h"
#include "autoveicolo.h"

class MainWindow : public QWidget
{
    Q_OBJECT
    friend class Controller;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void colorInizio() const;
    void mostraVeicoli(QList<QStringList>);
    const QString getParolaCercata() const;
    void nessunSelezionato();
    void veicoloRimossoShowBox();
    void targaPresenteBox();

public slots:
    void veicoloAggiunto();
    void openAddLayout() const;
    //void openModLayout();
    void richiestaRim();
    void cercaParola(QString);

private:

    addVeicoli* vistaAdd;
    modVeicoli* vistaMod;
    QVBoxLayout* mainLayout, *verticalLayout;
    QHBoxLayout* horizontal, *Bottonisotto;
    QPushButton* addButton,*modButton,*removeButton;
    QLineEdit* lineCerca;
    QTableWidget* veicoliTable;
    QStringList header;

    void setMainWindowStyle();

signals:
    void sEliminav(const int);

};


#endif // MAINWINDOW_H
