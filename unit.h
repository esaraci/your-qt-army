#ifndef UNIT_H
#define UNIT_H

#include <QString>
#include <iostream>
using std::string;

class Unit
{
  friend class AppManager;

private:
    QString name;
    int atk;
    int def;
    int price;
    bool premium;

protected:
    Unit (QString="",int=0, int=0, int=0, bool=0);

public:
    virtual ~Unit();
    Unit(const Unit&) =delete;
    Unit& operator=(const Unit&) =delete;

    QString getName() const;
    virtual int ATK() const;
    virtual int DEF() const;
    int getPrice() const;
    bool isPremium() const;

    bool operator==(const Unit&) const; //confrontano name
    bool operator!=(const Unit&) const;

};

#endif // UNIT_H
