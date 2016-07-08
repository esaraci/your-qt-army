#include "veichle.h"

Veichle::Veichle(QString N, int A, int D, int S, bool P) : Unit(N, A,  D, S, P) {}

int Veichle::DEF() const {
    return Unit::DEF()*1.1;
}
