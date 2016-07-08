#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QVector>
#include <QtXml>
#include "soldier.h"
#include "veichle.h"
#include "freeplayer.h"
#include "premiumplayer.h"
#include "battlemanager.h"

using namespace std;

class AppManager
{
private:


public:

    static MarketList* mp;
    static MarketList* load_marketPlace();

    static QVector<Player*> pv;
    static QVector<Player*> load_players();

    static Army* load_esercito(const QDomNodeList &);

    static void sanitize_armies(Unit*, const QVector<Player *> &);

    void save_marketPlace(MarketList*) const;

    void save_players(const QVector<Player*>&) const;

    static int try_login(QString, QString);

};

#endif // APPMANAGER_H
