#include <iostream>

using namespace std;

#include "nodo.h"
#include "listaenlazada.h"

int main()
{
    LinkedList List1;

    int elem1 = 8;
    int elem2 = 12;
    int elem3 = 27;
    int elem4 = 1;
    int elem5 = 19;
    int elem6 = 31;

    cout<<" /* Inicio: "<<endl;
    List1.print();
    cout<<endl<<endl;

    List1.insert(elem1);
    List1.insert(elem2);
    List1.insert(elem3);
    List1.insert(elem4);
    List1.insert(elem5);
    List1.insert(elem6);

///---------------------------------------------------------

    cout << "- 1) Maximo de forma iterativa" << endl; /// 1
    List1.max_iter();

    cout << "- 2) Maximo de forma recursiva" << endl; /// 2
    List1.max_rec_1();

    cout << "- 3) Imprimir lista de inicio a fin" << endl; /// 3
    List1.print_rec_1();

    cout << "- 4) Imprimir lista de fin a inicio" << endl; /// 4
    List1.print_inverse_rec_1();

    cout << "- 5) Imprimir lista inversa iterativa" << endl; /// 5
    List1.print_inverse_iter();

    List1.count_even(); /// 6

    cout << "- 7) Ordenando de menor a mayor" << endl; /// 7
    List1.sort_ascending();

    cout << "- 8) Ordenando de mayor a menor" << endl; /// 8
    List1.sort_descending();

    cout << "- 9) Imprimir con Begin - Next" << endl; /// 15
    List1.begin_last();

    cout << "- 10) Imprimir con Last - Previous" << endl; /// 16
    List1.next_previous();
}
