#ifndef FREEPLAYER_H
#define FREEPLAYER_H
#include "player.h"

class FreePlayer : public Player
{

public:
    FreePlayer(QString="", QString="", int=1000, int=0, int=0, Army* =0);
    FreePlayer(QString="", QString="", Army* =0);
    virtual void buy(Unit *);
    virtual void buy(QString); //utilità
    virtual void sell(Unit *);
    virtual void sell(QString); //utilità
    virtual int getATK() const;
    virtual int getDEF() const;
    void addWIN();
    void addLOSS();
};

#endif // FREEPLAYER_H
