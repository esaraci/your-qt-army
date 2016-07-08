#ifndef ARMY_H
#define ARMY_H
#include "marketlist.h"
#include "user.h"

class Army : public MarketList {

    friend class Player;

public:
    Army(Node* =0);
    ~Army();
    void add(Unit*);
    void remove(Unit*);
    void removeAll(Unit*);
    void wipe();
    int ATK() const;
    int DEF() const;
};

#endif // ARMY_H
