#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "user.h"
#include "unit.h"
#include "army.h"

class Player : public User
{
    friend class AppManager;

protected:
    int gold;
    int m_won;
    int m_lost;
    Army* esercito;
    static const MarketList marketRef;

public:

    Player(QString="", QString="", int=1000, int =0, int=0, Army* =0); //classe astratta non può essere costruita
    Player(QString="", QString="", Army* =0);

    virtual ~Player();
    Player& operator=(const Player&) =delete;
    Player(const Player&) =delete;

    static void linkMarket(const MarketList &);
    virtual void buy(Unit*)=0;
    virtual void buy(QString)=0;
    virtual void sell (Unit*)=0;
    virtual void sell (QString)=0;

    const Army& cloneArmy() const; //tutti i print su std output vanno rimossi. solo per debug

    virtual int getATK() const =0;
    virtual int getDEF() const =0;  

    int getGOLD() const;
    void addGOLD(int);

    int getM_WON() const;
    int getM_LOST() const;
    virtual void addWIN() =0;
    virtual void addLOSS() =0;

    bool operator==(const Player&) const;
    bool operator!=(const Player&) const;

};

#endif //   PLAYER_H
