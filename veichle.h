#ifndef VEICHLE_H
#define VEICHLE_H
#include "unit.h"

class Veichle : public Unit
{
public:
    Veichle(QString ="", int=0, int=0, int=0, bool=0);
    virtual int DEF() const;
};

#endif // VEICHLE_H
