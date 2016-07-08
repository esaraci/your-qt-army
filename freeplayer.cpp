#include "freeplayer.h"


FreePlayer::FreePlayer(QString U, QString P, int G, int W, int L, Army* E) : Player(U,P,G,W,L,E) {}
FreePlayer::FreePlayer(QString U, QString P, Army* E) : Player(U,P,E) {}

void FreePlayer::buy(Unit* u) {
    if (!(u->isPremium()))
        if(u->getPrice()<=getGOLD()) {
            addGOLD(-u->getPrice());
            esercito->add(u);
        }
}

void FreePlayer::buy(QString s) {

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

void FreePlayer::sell(Unit* u) {
    esercito->remove(u);
    addGOLD(u->getPrice()/2);
}

void FreePlayer::sell(QString s) {
    MarketList::Iterator it=marketRef.begin();
    bool trovato=false;
    while (it!=marketRef.end() && !trovato) {
        if((*esercito)[it]->unitPtr->getName()==s) {
            trovato=true;
            sell((*esercito)[it]->unitPtr);
        }
        else
            ++it;
    }
}

int FreePlayer::getATK() const {
    if (esercito && (!(esercito->isEmpty())))
       return esercito->ATK();
   return 0;
}

int FreePlayer::getDEF() const {
   if (esercito && (!(esercito->isEmpty())))
        return esercito->DEF();
   return 0;
}

void FreePlayer::addWIN() {
    m_won++;
    addGOLD(250);
}

void FreePlayer::addLOSS() {
    m_lost++;
    addGOLD(-150);
}

