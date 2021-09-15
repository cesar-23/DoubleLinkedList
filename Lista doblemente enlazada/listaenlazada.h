#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include "nodo.h"

class LinkedList{
private:
    Nodo *header; /// Nodos centinelas
    Nodo *trailer;
    Nodo *pActual;                            /// 9 ^
public:
    LinkedList(); /// Constructor

    void insert(int elem);
    void remove();
    void remove_by_elem(int elem);
    void find(int elem);
    void print();

    /// Actividades
    void max_iter();                          /// 1 ^
    void max_rec(Nodo *nuevo, int maximum);   /// 2 ^
    void max_rec_1();
    void print_rec(Nodo *nuevo);              /// 3 ^
    void print_rec_1();
    void print_inverse_rec(Nodo *nuevo);      /// 4 ^
    void print_inverse_rec_1();
    void print_inverse_iter();                /// 5 ^
    void count_even();                        /// 6 ^
    void sort_ascending();                    /// 7 ^
    void sort_descending();                   /// 8 ^

    void Begin();                             /// 10 ^
    void Last();                              /// 11 ^
    void Next();                              /// 12 ^
    void Previous();                          /// 13 ^
    int GetDato();                            /// 14 ^

    void begin_last();                        /// 15 ^
    void next_previous();                     /// 16 ^

    ~LinkedList();
};

LinkedList::LinkedList(){
    header = new Nodo;
    trailer = new Nodo;
    header -> next = trailer;
    trailer -> prev = header;
    header -> prev = NULL;
    trailer -> next = NULL;
}

void LinkedList::insert(int _elem){
    Nodo *nuevo = new Nodo(_elem);

    nuevo -> prev = trailer -> prev;
    nuevo -> next = trailer;

    trailer -> prev -> next = nuevo;
    trailer -> prev = nuevo;
}

void LinkedList::remove(){
    Nodo *nuevo = trailer -> prev -> prev;

    delete trailer -> prev;

    trailer -> prev = nuevo;
    nuevo -> next = trailer;
}

void LinkedList::remove_by_elem(int _elem){
    Nodo *nuevo = header -> next;
    Nodo *tmp1 = nuevo -> next;
    Nodo *tmp2 = nuevo -> prev;
    int cont = 0;

    if (header -> next != NULL){
        while (nuevo != trailer){
            if (nuevo -> elem == _elem){
                tmp1 -> prev = tmp2;
                tmp2 -> next = tmp1;
                cont++;
            }
            nuevo = nuevo -> next;
            tmp1 = nuevo -> next;
            tmp2 = nuevo -> prev;
        }
        if (cont == 0){
            cout << "No se encontro el elemento " << _elem <<endl;
        }
        else {
            cout << "Se elimino correctamente el elemento " << _elem << endl;
        }
    }
    else {
        cout << "La lista no existe" << endl;
    }

}

void LinkedList::find(int _elem){
    Nodo *nuevo = header -> next;
    int cont=0;

    if (header -> next -> elem != NULL){
        while (nuevo -> next != NULL){
            if (nuevo -> elem == _elem){
                cout << "Se encontro " << _elem << " en la lista" <<endl;
                cont++;
            }
            nuevo = nuevo -> next;
        }
        if (cont == 0){
            cout << "No se encontro " << _elem << " en la lista" <<endl;
        }
    }
    else {
        cout << "No hay elementos en la lista" << endl;
    }
}

void LinkedList::print(){
    Nodo *nuevo = header -> next;

    while (nuevo != trailer){
        //cout << nuevo -> prev -> elem << " <- ";
        cout << nuevo -> elem << " -> ";
        //cout << nuevo -> next -> elem << " ... ";
        nuevo = nuevo -> next;
    }
    cout << "NULL";
}

/// Actividades

void LinkedList::max_iter(){
    Nodo *nuevo = header -> next;
    int maximum = nuevo -> elem;

    while (nuevo != trailer){
        if (nuevo -> elem >= maximum){
            maximum = nuevo -> elem;
        }
        nuevo = nuevo -> next;
    }
    cout << "El valor maximo es " << maximum << endl << endl;
}

void LinkedList::max_rec(Nodo *nuevo, int maximum){

    if (nuevo == trailer){
        cout << "El valor maximo es " << maximum << endl << endl;
        return;
    }
    if (nuevo -> elem >= maximum){
        maximum = nuevo -> elem;
    }
    nuevo = nuevo -> next;

    max_rec(nuevo, maximum);
}

void LinkedList::max_rec_1(){
    Nodo *nuevo = header -> next;
    int maximum = nuevo -> elem;

    max_rec(nuevo, maximum);
}

void LinkedList::print_rec(Nodo *nuevo){
    if (nuevo == trailer){
        cout << "NULL" << endl << endl;
        return;
    }
    else {
        cout << nuevo -> elem << " -> ";
        nuevo = nuevo -> next;
        print_rec(nuevo);
    }
}

void LinkedList::print_rec_1(){
    Nodo *nuevo = header -> next;
    print_rec(nuevo);
}

void LinkedList::print_inverse_rec(Nodo *nuevo){
    if (nuevo == header){
        cout << "NULL" << endl << endl;
        return;
    }
    else {
        cout << nuevo -> elem << " -> ";
        nuevo = nuevo -> prev;
        print_inverse_rec(nuevo);
    }
}

void LinkedList::print_inverse_rec_1(){
    Nodo *nuevo = trailer -> prev;
    print_inverse_rec(nuevo);
}

void LinkedList::print_inverse_iter(){
    Nodo *nuevo = trailer -> prev;

    while (nuevo != header){
        cout << nuevo -> elem << " -> ";
        nuevo = nuevo -> prev;
    }
    cout << "NULL" << endl << endl;
}

void LinkedList::count_even(){
    Nodo *nuevo = header -> next;
    int cont=0;

    while (nuevo != trailer){
        if (nuevo -> elem % 2 == 0){
            cont++;
        }
        nuevo = nuevo -> next;
    }
    if (cont == 0){
        cout << "- 6) No existe un numero par en la lista" << endl << endl;
    }
    else {
        cout << "- 6) Hay " << cont << " numeros pares en la lista" << endl << endl;
    }
}

void LinkedList::sort_ascending(){
    Nodo *aux1, *aux2;
    int tmp;
    aux1 = header -> next;

    while(aux1 != trailer -> prev){
        aux2 = aux1;
        while (aux2 != trailer ){
            if (aux2 -> elem < aux1 -> elem){
                tmp = aux1 -> elem;
                aux1 -> elem = aux2 -> elem;
                aux2 -> elem = tmp;
            }
            aux2 = aux2 -> next;
        }
        aux1 = aux1 -> next;
    }

    Nodo *nuevo1 = header -> next;

    while (nuevo1 != trailer){
        //cout << nuevo1 -> prev -> elem << " <- ";
        cout << nuevo1 -> elem << " -> ";
        //cout << nuevo1 -> next -> elem << " ... ";
        nuevo1 = nuevo1 -> next;
    }
    cout << "NULL" << endl << endl;
}

void LinkedList::sort_descending(){
    Nodo *aux1, *aux2;
    int tmp;
    aux1 = header -> next;

    while(aux1 != trailer -> prev){
        aux2 = aux1;
        while (aux2 != trailer ){
            if (aux2 -> elem > aux1 -> elem){
                tmp = aux1 -> elem;
                aux1 -> elem = aux2 -> elem;
                aux2 -> elem = tmp;
            }
            aux2 = aux2 -> next;
        }
        aux1 = aux1 -> next;
    }

    Nodo *nuevo1 = header -> next;

    while (nuevo1 != trailer){
        //cout << nuevo1 -> prev -> elem << " <- ";
        cout << nuevo1 -> elem << " -> ";
        //cout << nuevo1 -> next -> elem << " ... ";
        nuevo1 = nuevo1 -> next;
    }
    cout << "NULL" << endl << endl;
}



void LinkedList::Begin(){
    pActual = header -> next;
}

void LinkedList::Last(){
    pActual = trailer -> prev;
}

void LinkedList::Next(){
    pActual = pActual -> next;
}

void LinkedList::Previous(){
    pActual = pActual -> prev;
}

int LinkedList::GetDato(){
    int aux;
    aux = pActual -> elem;
    return aux;
}

void LinkedList::begin_last(){
    Begin();
    while (pActual != trailer){
        cout << pActual -> elem << " -> ";
        Next();
    }
    cout << "NULL" << endl << endl;
}

void LinkedList::next_previous(){
    Last();
    while (pActual != header){
        cout << pActual -> elem << " -> ";
        Previous();
    }
    cout << "NULL" << endl << endl;
}

LinkedList::~LinkedList(){
    while (header -> next != trailer){
        remove();
    }
    delete header;
    delete trailer;
}

#endif // LISTAENLAZADA_H_INCLUDED
