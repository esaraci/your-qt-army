#include <QApplication>
#include <QVector>
#include <iostream>
#include "battlemanager.h"
#include "appmanager.h"
#include "loginwindow.h"
#include <QtCore>

using namespace std;

int main(int argc, char *argv[])
{

    MarketList* marketPlace = AppManager::mp;
    Player::linkMarket(*marketPlace);

    QApplication a(argc, argv);
    LoginWindow w;
    w.show();

    return a.exec();
}
