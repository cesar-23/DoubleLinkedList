#ifndef NODE_H
#define NODE_H
 
#include <iostream>
 
using namespace std;
 
template <typename T>
class Node
{
    private: 
        Node<T> *next;
        T element;
        Node<T> *previous;
    public:
        Node(T);
        Node();

        ~Node();

        void print();

        //setters
        void setNext(Node<T> *);
        void setPrevious(Node<T> *);
        void setElement(T);

        //getters
        Node<T>* getNext()const;
        Node<T>* getPrevious()const;
        T getElement()const;

        friend std::ostream& operator <<(std::ostream &out,const Node<T>& p){
            out<<p.getElement();
            return out;
        }
};


//Constructor
template<typename T>
Node<T>::Node(T _element){ 
    this->element = _element;
    this->next = nullptr;
    this->previous = nullptr;
}

//Constructor por defecto   
template<typename T>
Node<T>::Node(){ 
    this->element = 0;
    this->next = nullptr;
    this->previous = nullptr;
}
 
//Destructor
template<typename T>
Node<T>::~Node(){}

// Imprimir un Nodo
template<typename T>
void Node<T>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << " <-" <<element << "-> ";
}

// Setter de Next
template<typename T>
void Node<T>::setNext(Node<T> *_next)
{
    next = _next;
}

// Setter de Previous
template<typename T>
void Node<T>::setPrevious(Node<T> *_previous)
{
    previous = _previous;
}

// Setter de element
template<typename T>
void Node<T>::setElement(T _element)
{
    element = _element;
}

//Getter de next
template<typename T>
Node<T>* Node<T>::getNext()const{
    return next;
}

//Getter de next
template<typename T>
Node<T>* Node<T>::getPrevious()const{
    return previous;
}

//Getter de element
template<typename T>
T Node<T>::getElement()const{
    return element;
}

#endif // NODE_H