/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *potenza;
    QLabel *label;
    QLabel *label_2;
    QComboBox *classeambientale;
    QLabel *label_3;
    QSpinBox *assi;
    QPushButton *btncalcola;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 322);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        potenza = new QPlainTextEdit(centralWidget);
        potenza->setObjectName(QStringLiteral("potenza"));
        potenza->setGeometry(QRect(90, 30, 221, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 0, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 70, 141, 16));
        classeambientale = new QComboBox(centralWidget);
        classeambientale->setObjectName(QStringLiteral("classeambientale"));
        classeambientale->setGeometry(QRect(90, 100, 211, 25));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 140, 121, 16));
        assi = new QSpinBox(centralWidget);
        assi->setObjectName(QStringLiteral("assi"));
        assi->setGeometry(QRect(90, 170, 48, 26));
        btncalcola = new QPushButton(centralWidget);
        btncalcola->setObjectName(QStringLiteral("btncalcola"));
        btncalcola->setGeometry(QRect(450, 40, 221, 151));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Kw", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Classe ambientale", Q_NULLPTR));
        classeambientale->clear();
        classeambientale->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Euro 0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Euro 1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Euro 2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Euro 3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Euro 4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Euro 5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Euro 6", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "Numero di assi", Q_NULLPTR));
        btncalcola->setText(QApplication::translate("MainWindow", "CALCOLA  BOLLO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
