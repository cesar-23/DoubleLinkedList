#include "doublelinkedlist.h"
#include <iostream> 

using namespace std;
 
int main()
{       
    List<string> lista;
    lista.insert("Pepe");
    lista.insert("Marta");
    lista.insert("Carlo");
    lista.insert("Juan");
    lista.insert("Mario");
    lista.insert("Robert");
    lista.insert("Chillah");

    cout<<lista<<endl;

    lista.remove("Pepe");

    lista.print();
    lista.search("Mario");
    return 0;
}