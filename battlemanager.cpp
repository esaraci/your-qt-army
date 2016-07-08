#include "battlemanager.h"
using namespace std;


BattleManager::BattleManager () {}

Player* BattleManager::fight(Player&p1, Player &p2) const
{
    Player* winner = whoWins(p1,p2);
    Player* loser = 0;
    if (*winner==p1)
        loser=&p2;
    if (*winner==p2)
        loser=&p1;

    if (dynamic_cast<FreePlayer*>(winner) && dynamic_cast<PremiumPlayer*>(loser)) //solo se loser era premium.
        if (qrand() % 10+1 == 1) {
            Player* aux=winner;
            winner=loser;
            loser=aux;
        }

    if (winner!=0) {
        winner->addWIN();
        loser->addLOSS();
    }
    return winner;
}


Player* BattleManager::fight(QString p1, QString p2) const {

    if (p1==p2)
        return 0;

    Player* p1ptr;
    Player* p2ptr;
    for (int i=0; i < AppManager::pv.size();i++) {
        if (AppManager::pv[i]->Username() == p1)
            p1ptr=AppManager::pv[i];
        if(AppManager::pv[i]->Username() == p2)
            p2ptr=AppManager::pv[i];
    }

    return fight(*p1ptr,*p2ptr);
}

Player* BattleManager::whoWins(Player& p1, Player& p2) const{

    if (p1.getATK()+p1.getDEF()>p2.getATK()+p2.getDEF())
        return &p1;
    if (p1.getATK()+p1.getDEF()<p2.getATK()+p2.getDEF())
        return &p2;
    return 0;
}
