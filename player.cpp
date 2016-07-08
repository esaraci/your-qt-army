#include "player.h"

const MarketList Player::marketRef;

Player::Player(QString U, QString P, int G, int W, int L, Army* E) : User(U,P), gold(G), m_won(W), m_lost(L), esercito(E) {}

Player::Player(QString U, QString P, Army* E) : User(U,P), gold(1000), m_won(0), m_lost(0), esercito(E) {}

Player::~Player() {}

void Player::linkMarket(const MarketList &marketPlace) {
    const_cast<MarketList&>(marketRef) = marketPlace;
}

//void Player::print_army() const { //solo per debug
//    if(esercito)
//        esercito->print_list();
//}

const Army& Player::cloneArmy() const {
        return *esercito;
}



int Player::getGOLD() const {
    return gold;
}

int Player::getM_LOST() const {
    return m_lost;
}
int Player::getM_WON() const {
    return m_won;
}

void Player::addGOLD(int bonus) {
    gold +=bonus;
    if (gold<0)
        gold=0;
}

bool Player::operator==(const Player& p2) const {
    return this==&p2;
}

bool Player::operator !=(const Player& p2) const {
    return this!=&p2;
}

