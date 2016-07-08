#ifndef MARKETLIST_H
#define MARKETLIST_H

#include <QVector>
#include <QString>
#include "unit.h"

class MarketList {

private:

protected:

    class Node {
    public:
        Node( Unit * =0, Node * =0);
        ~Node();
        Unit* unitPtr;
        Node* next;
    };

    Node* first;

public:

    class Iterator {
        friend class MarketList;
        friend class Army;
    private:
        Node* punt;

    public:
        Iterator();
        bool operator== (Iterator i) const;
        bool operator!= (Iterator i) const;
        Iterator& operator++();
    };

    MarketList(Node* =0);
    ~MarketList();
    bool isEmpty() const;
    Iterator begin() const;
    Iterator end() const;
    Node* operator [] (Iterator) const;
    Unit* operator [] (QString) const;
    void add(Unit*);
    void remove(Unit*);
    void remove(QString); //per comodità, da togliere.
    void wipe();
    void print_list() const;
};

#endif // MARKETLIST_H
