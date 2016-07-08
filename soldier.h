#ifndef SOLDIER_H
#define SOLDIER_H

#include "unit.h"


class Soldier : public Unit
{
public:
    Soldier(QString ="", int=0, int=0, int=0, bool=0);
    virtual int ATK() const;
};

#endif // SOLDIER_H
