#include "premiumplayer.h"

PremiumPlayer::PremiumPlayer(QString U, QString P, int G, int W, int L, Army* E) : Player(U,P,G,W,L,E) {}
PremiumPlayer::PremiumPlayer(QString U, QString P, Army* E) : Player(U,P,E) {}


void PremiumPlayer::buy(Unit* u) {
     if(u->getPrice()<=getGOLD()) {
         addGOLD(-u->getPrice());
         esercito->add(u);
     }
}

void PremiumPlayer::buy(QString s) {

    MarketList::Iterator it=marketRef.begin();
    bool trovato=false;

    while (it!=marketRef.end() && !trovato) {
        if(marketRef[it]->unitPtr->getName()==s) {
            trovato=true;
            buy(marketRef[it]->unitPtr);
        }
        else
            ++it;
    }
}

void PremiumPlayer::sell(Unit* u) {
    esercito->remove(u);
    addGOLD(u->getPrice()/premiumMultiplier);
}

void PremiumPlayer::sell(QString s) {

    Army::Iterator it=esercito->begin();
    bool trovato=false;

    while (it!=esercito->end() && !trovato) {
        if((*esercito)[it]->unitPtr->getName()==s) {
            trovato=true;
            sell((*esercito)[it]->unitPtr);
        }
        else
            ++it;
    }
}

int PremiumPlayer::getATK() const {
   if (esercito && (!(esercito->isEmpty())))
       return static_cast<int>(esercito->ATK()*premiumMultiplier);
   return 0;
}

int PremiumPlayer::getDEF() const {
   if (esercito && (!(esercito->isEmpty())))
        return static_cast<int>(esercito->DEF()*premiumMultiplier);
   return 0;
}

void PremiumPlayer::addWIN() {
    m_won++;
    addGOLD(static_cast<int>(250*premiumMultiplier));
}

void PremiumPlayer::addLOSS() {
    m_lost++;
    addGOLD(static_cast<int>(-150/premiumMultiplier));
}
