#ifndef PREMIUMPLAYER_H
#define PREMIUMPLAYER_H
#include "player.h"

class PremiumPlayer : public Player
{

public:
    PremiumPlayer(QString="", QString="", int=1000, int=0, int=0, Army* =0);
    PremiumPlayer(QString="", QString="", Army* =0);
    static const double premiumMultiplier = 1.2;
    virtual void buy(Unit*);
    virtual void buy(QString);
    virtual void sell(Unit*);
    virtual void sell(QString);
    virtual int getATK() const;
    virtual int getDEF() const;
    virtual void addWIN();
    virtual void addLOSS();

};

#endif // PREMIUMPLAYER_H
