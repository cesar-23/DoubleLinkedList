#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#include <iostream>
#include "Node.h"

template<typename T>
class LinkedList;

template<typename T>
class LinkedList{
    private:
        Node<T>* head;
        int size;
    public:
        LinkedList();
        LinkedList(T);
        LinkedList(const LinkedList<T>&);
        LinkedList(LinkedList<T> &&);
        LinkedList<T>& operator=(const LinkedList<T> &);
        LinkedList<T>& operator=(LinkedList<T>&&);
        ~LinkedList();
        
        void PushBack(T);
        void RemoveElem(T);

        Node<T>* getHead();
        int getSize();

        friend std::ostream &operator << (std::ostream &out, LinkedList &o){
            Node<T>* aux=o.getHead();
            while(aux!=nullptr){
                out<<*aux<<" -> ";
                aux=aux->getNext();
            }
            return out;
        }
};

template<typename T>
LinkedList<T>::LinkedList(){
    this->head=nullptr;
    this->size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T value){
    this->head=new Node<T>(value);
    this->size=1;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T>::~LinkedList(){
    Node <T>*aux=nullptr;
    while (head!=nullptr){
        aux=head;
        head=head->getNext();
        delete aux;
    }
}

///////////////////////////////////////////////////////////////////

template<typename T>
void LinkedList<T>::PushBack(T elem){
    Node<T>* new_node = new Node<T>(elem);
    Node<T>* aux=head;
    Node<T>* aux2=head;
    if(head==nullptr){
        head=new_node;
    }else{
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
            aux2=aux2->getNext();
        }
        aux->setNext(new_node);
        new_node->setPrev(aux);
    }
    size++;
}

template <typename T>
void LinkedList<T>::RemoveElem(T elem){
    Node<T> *temp = head;
    Node<T> *temp1 = head->getNext();
 
    int cont = 0;
 
    if (head->getData() == elem) {
        head = temp->getNext();
    } else {
        while (temp1) {
            if (temp1->data == elem) {
                Node<T> *aux_node = temp1;
                temp->getNext() = temp1->getNext();
                delete aux_node;
                cont++;
                size--;
            }
            temp = temp->getNext();
            temp1 = temp1->getNext();
        }
    }
    if (cont == 0) {
        std::cout << "No existe el dato " << "\n";
    }
}

/////////////////////////////////////////////////////////////////////

template<typename T>
Node<T>* LinkedList<T>::getHead(){
    return head;
}

template<typename T>
int LinkedList<T>::getSize(){
    return size;
}

#endif