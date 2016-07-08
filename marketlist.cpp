#include "marketlist.h"
#include "appmanager.h"
#include <iostream>
#include <QDebug>
using namespace std;

MarketList::MarketList (Node* AN) : first(AN) {} //costruttore di MarketList

MarketList::~MarketList() {
   wipe();
}

MarketList::Node::Node (Unit *U, Node* AN) : unitPtr(U), next(AN) {}   //costruttore di Node

MarketList::Node::~Node() {
    AppManager::sanitize_armies(unitPtr, AppManager::pv);
    delete unitPtr;
}

MarketList::Iterator::Iterator() {}

bool MarketList::Iterator::operator== (Iterator i) const {
    return punt==i.punt;
}

bool MarketList::Iterator::operator!= (Iterator i) const {
    return punt!=i.punt;
}

MarketList::Iterator& MarketList::Iterator::operator++ () {
    if(punt)
        punt=punt->next;
    return *this;
}

MarketList::Iterator MarketList::begin() const{
    Iterator aux;
    aux.punt=first;
    return aux;
}

MarketList::Iterator MarketList::end() const {
    Iterator aux;
    aux.punt=0;
    return aux;
}

MarketList::Node* MarketList::operator [](Iterator it) const {
    return it.punt;
}

Unit* MarketList::operator [](QString s) const {
    Iterator it=begin();
    while (it!=end()) {
        if (it.punt->unitPtr->getName()==s)
            return it.punt->unitPtr;
        ++it;
    }
    return 0;
}


bool MarketList::isEmpty() const {
    if(first)
        return 0;
    return 1;
}

void MarketList::remove(Unit* u) { //rimuove la prima occorrenza di unit
    Node* prec=0;
    bool trovato=false;
    Iterator i=begin();
    while ((i != end()) && !trovato) {
        if (i.punt->unitPtr->getName() == u->getName())
        {
            trovato=true;
            if (prec) //se prec esiste sono "in mezzo" alla lista, creo il ponte.
                prec->next=i.punt->next; //se next è null nessun problema, fine della lista
            else //se prec non esiste, sto rimuovendo il primo
                first=i.punt->next; //se è null non c'è problema

            //non responsabilità di MarketList togliere i nodi degi army.
            delete i.punt;
        }
        else {
            prec=i.punt; //avanza prec
            ++i; //avanza iterator
        }
    }
}

void MarketList::remove(QString s) { //rimuove la prima occorrenza di unit

    Node* prec=0;
    bool trovato=false;
    Iterator i=begin();
    while ((i != end()) && !trovato) {
        if (i.punt->unitPtr->getName() == s)
        {
            trovato=true;
            if (prec) //se prec esiste sono "in mezzo" alla lista, creo il ponte.
                prec->next=i.punt->next; //se next è null nessun problema, fine della lista
            else //se prec non esiste, sto rimuovendo il primo
                first=i.punt->next; //se è null non c'è problema


            delete i.punt;
        }
        else {
            prec=i.punt; //avanza prec
            ++i; //avanza iterator
        }
    }
}


void MarketList::add(Unit* u) {
    if (!first) //lista vuota
       first = new Node(u);
    else {
        Node* a = new Node(u,first);
        first=a;
    }
}

void MarketList::wipe() {
    Node* aux=first;

    while (aux!=0) {
        first=first->next;
        delete aux;
        aux=first;
    }
}


void MarketList::print_list() const {
    if (first)
        for (Iterator i=begin(); i!=end(); ++i)
            cout << i.punt->unitPtr->getName().toStdString() <<endl;
    else
        cout << "Empty List" <<endl;
}
