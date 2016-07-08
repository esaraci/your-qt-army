#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>
#include "player.h"
#include "appmanager.h"

class userWindow : public QMainWindow
{
    Q_OBJECT

private:
    int utenteLoggato;
public:
    userWindow(int , QWidget *parent = 0);

        QWidget *centralWidget;
        QGroupBox *groupBox_profilo;
        QLabel *label;
        QLabel *label_2;
        QLabel *label_3;
        QLabel *label_4;
        QLabel *label_5;
        QLabel *label_6;
        QLabel *label_7;
        QLabel *lblUsername;
        QLabel *lblATK;
        QLabel *lblDEF;
        QLabel *lblTipo;
        QLabel *lblGold;
        QLabel *lblVinte;
        QLabel *lblPerse;
        QTableWidget *tableArmy;
        QLabel *label_9;
        QPushButton *btnVendi;
        QGroupBox *groupBox_nemici;
        QTableWidget *tablePlayers;
        QPushButton *btnAttacca;
        QGroupBox *groupBox_marketPlace;
        QTableWidget *tableMarketPlace;
        QPushButton *btnCompra;


signals:

public slots:

        void updateUserProfile();
        void updatePlayers();
        void updateMarketPlace();
        void tableArmyClicked();
        void tableMarketPlaceClicked();
        void tablePlayersClicked();
        void vendi();
        void fight();
        void compra();
        void salva();

};

#endif // USERWINDOW_H
