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
#include <QTableView>
#include <QFile>
#include <QStringList>
#include <QSizePolicy>
#include <QString>



#include "viewlistaveicoli.h"
#include "addveicoli.h"
#include "modveicoli.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void colorInizio() const;

public slots:
    void openAddLayout();
    void openModLayout();
    void colorAutomobile();
    void colorAutotreno();
    void colorAutocarro();
    void colorMinAssi();
    void colorMaxAssi();
    void colorEsonero();


private:
    QVBoxLayout* mainLayout, *verticalLayout;
    QHBoxLayout* horizontal, *Bottonisotto;
    QPushButton* removeFilter, *checkAutomobile, *checkAutocarro, *checkAutotreno, *checkMinAssi, *checkMaxAssi, *checkEsonero;
    QPushButton* addButton,*modButton,*removeButton;
    QLineEdit* lineCerca;
    QGroupBox* veicoliGroup1;
    QTableWidget* veicoliTable;
    QStringList header;

    addVeicoli* vistaAdd;
    modVeicoli* vistaMod;

    void setMainWindowStyle();

};


#endif // MAINWINDOW_H
