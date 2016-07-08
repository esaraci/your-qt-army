#include "unit.h"

using namespace std;

/*  DISTRUTTORI E COSTRUTTORI   */

Unit::Unit(QString N, int A, int D, int S, bool P) :name(N), atk(A), def(D), price(S), premium(P) {}

/*  IMPLEMENTAZIONE METODI  */

Unit::~Unit() {}

int Unit::ATK() const {
    return atk;
}

int Unit::DEF() const {
    return def;
}

QString Unit::getName() const {
    return name;
}

int Unit::getPrice() const {
    return price;
}

bool Unit::isPremium() const {
    return premium;
}


/* RIDEFINIZIONE OPERATORI  */

bool Unit::operator==(const Unit& x) const {
    return name==x.name;
}

bool Unit::operator!=(const Unit& x) const {
    return name!=x.name;
}
