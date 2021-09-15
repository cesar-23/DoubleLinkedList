#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <cstddef> // NULL

#include <iostream>

using namespace std;

class Nodo{
private:
    int elem;
    Nodo *next; /// Siguiente / Next
    Nodo *prev; /// Anterior / Previous

    friend class LinkedList;
public:
    Nodo();
    Nodo(int _elem);
};

Nodo::Nodo(){
    elem = NULL;
    next = NULL;
    prev = NULL;
}

Nodo::Nodo(int _elem){
    elem = _elem;
    next = NULL;
    prev = NULL;
}

#endif // NODO_H_INCLUDED
