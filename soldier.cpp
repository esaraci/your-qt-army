#include "soldier.h"


Soldier::Soldier(QString N, int A, int D, int S, bool P) : Unit(N, A,  D, S, P) {}

int Soldier::ATK() const {
    return Unit::ATK() *1.1;
}

//carro, aereo, nave saranno identiche a soldier, l'unica differenza sarà la diversa implementazione dei metodi ATK() DEF() e HP()
//già implementati in forma base nella classe base.
