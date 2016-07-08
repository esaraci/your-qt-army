#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H
#include "appmanager.h"
#include "premiumplayer.h"
#include "freeplayer.h"
#include <QtGlobal>

class BattleManager
{

private:
    Player* whoWins(Player &, Player &) const;

public:
    BattleManager();
    Player *fight(Player &, Player &) const;
    Player *fight(QString, QString) const;//void
};

#endif // BATTLEMANAGER_H
