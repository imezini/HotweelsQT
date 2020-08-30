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


public slots:
    void openAddLayout() const;
    void openModLayout();
    void colorAutomobile();
    void colorAutotreno();
    void colorAutocarro();
    void colorMinAssi();
    void colorMaxAssi();
    void colorEsonero();

private:

    addVeicoli* vistaAdd;
    modVeicoli* vistaMod;

    QVBoxLayout* mainLayout, *verticalLayout;
    QHBoxLayout* horizontal, *Bottonisotto;
    QPushButton* removeFilter, *checkAutomobile, *checkAutocarro, *checkAutotreno, *checkMinAssi, *checkMaxAssi, *checkEsonero;
    QPushButton* addButton,*modButton,*removeButton;
    QLineEdit* lineCerca;
    QGroupBox* veicoliGroup1;
    QTableWidget* veicoliTable;
    QStringList header;

    void setMainWindowStyle();

signals:
  //  void signOpenAddWindow();
    void filtroTutti();
    void filtroAutomobile();
    void filtroAutotreno();
    void filtroAutocarro();
    void filtroMinAssi();
    void filtroMaxAssi();
    void filtroEsonero();
 //   void signEsportaPDFClienti();

};


#endif // MAINWINDOW_H
