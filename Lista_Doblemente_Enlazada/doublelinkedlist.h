#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "node.h"
 
using namespace std;
 
template <class T>
class List
{
    private:
        Node<T> *m_head;
        Node<T> *last;
        int size;
    public:
        List();
        List(T);
        ~List();

        void insert(T);
        void search(T);
        void remove(T);
        void print();

        friend std::ostream& operator <<(std::ostream &pout,List<T>& p){
            Node<T>* actual=p.getHead();
            pout<<"[ ";
            while(actual!=nullptr){
                pout<<*actual<<" "; 
                actual=actual->getNext();
            }
            pout<<" ]";
            return pout;
        }

        int getSize()const;
        Node<T>* getHead();
        Node<T>* getLast();
        
};

template<typename T>
List<T>::List(){
    this->size = 0;
    this->m_head = nullptr;
    this->last = nullptr;
}

template<typename T>
List<T>::List(T valor){
    this->size = 1;
    this->m_head = new Node<T>(valor);
    this->last = m_head;
}
 
template <typename T>
List<T>::~List(){ 
}

// Insertar al final
template<typename T>
void List<T>::insert(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
        last = m_head;
    } 
    else {
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        last->setNext(new_node); 
        new_node->setPrevious(last);
        last = new_node;
        temp->setNext(new_node);
    }
    size++;
}

// Eliminar por data del nodo
template<typename T>
void List<T>::remove(T data_)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = NULL;

    while((temp != NULL) && (temp->getElement() != data_)){
        temp1 = temp;
        temp = temp->getNext();
    }

    if(temp == m_head){
        m_head = m_head->getNext();
        m_head->setPrevious(NULL);
    }
    else if(temp == last){
        temp1->setNext(NULL);
        last = temp1;
        delete temp;
    }
    else {
        temp1->setNext(temp->getNext());
        temp->getNext()->setPrevious(temp1);
        delete temp;
    }
}

// Buscar el dato de un nodo
template<typename T>
void List<T>::search(T data_)
{
    Node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;
 
    while (temp) {
        if (temp->getElement() == data_) {
            cout << "El dato si existe"<< endl;
            cont2++;
        }
        temp = temp->getNext();
        cont++;
    }
 
    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl;
}

// Imprimir la Lista
template<typename T>
void List<T>::print()
{   
    Node<T> *temp = last;
    if (!last) {
        cout << "La Lista está vacía " << endl;
    } 
    else {
        while (temp) {
            temp->print();
            temp = temp->getPrevious();
        }
    }
    cout << endl;
}

template<typename T>
int List<T>::getSize()const{
    return this->size;
}

template<typename T>
Node<T>* List<T>::getHead(){
    return m_head;
}

template<typename T>
Node<T>* List<T>::getLast(){
    return last;
}

#endif // DOUBLELINKEDLIST_H