//COSA RIMANE DA FARE
//  -distruttore di Army???, distruttore di Node
//  -assegnazione fra Army e Node?

#include <iostream>
#include "army.h"

using namespace std;

Army::Army (Node* AN) : MarketList(AN) {} //costruttore di Army

Army::~Army() {
    wipe();
}


void Army::add(Unit* u) {
    if (!first)
       first = new Node(u);
    else {
        Node* a = new Node(u,first);
        first=a;
    }
}


void Army::remove(Unit* u) {

    Node* prec=0;
    bool trovato=false;
    Iterator i=begin();

    while ((i != end()) && (trovato==false)) {
        if (i.punt->unitPtr->getName() == u->getName())
        {
            trovato=true;
            if (prec) //se prec esiste sono "in mezzo" alla lista, creo il ponte.
                prec->next=i.punt->next; //se next è null nessun problema, fine della lista
            else {
                //se prec non esiste, sto rimuovendo il primo
                first=i.punt->next; //se è null non c'è problema
                i.punt=0; //i.punt non punta più a niente && non ho eliminato l'unità vera e propria.
            }
        }
        else {
            prec=i.punt; //avanza prec
            ++i; //avanza iterator
        }
    }
}

void Army::removeAll(Unit *u) {

    Node* prec=0;

    for (Army::Iterator it=begin(); it!=end(); ++it) {
       if (it.punt) {

        if (it.punt->unitPtr->getName() == u->getName())

           if (prec) //se prec esiste sono "in mezzo" alla lista, creo il ponte.
               prec->next=it.punt->next; //se next è null nessun problema, fine della lista
           else {
                //se prec non esiste, sto rimuovendo il primo
                first=it.punt->next; //se è null non c'è problema
                it.punt=0; //i.punt non punta più a niente && non ho eliminato l'unità vera e propria.
           }
        else
            prec=it.punt; //avanza prec

       }
    }

}


void Army::wipe() {
    Node* aux=first;

    while(aux!=0) {
        first=first->next;
        delete aux;
        aux=first;
    }

}

int Army::ATK() const {
    int totATK = 0;   
    for (Iterator i=begin(); i!=end(); ++i)
        totATK+=i.punt->unitPtr->ATK();
    return totATK;
}

int Army::DEF() const {
    int totDEF = 0;
    for (Iterator i=begin(); i!=end(); ++i)
        totDEF+=i.punt->unitPtr->DEF();

    return totDEF;
}
