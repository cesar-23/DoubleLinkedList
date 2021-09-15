#include <iostream>
#include "LinkedListd.h"
#include "People.h"
using namespace std;

void Personas(){
    People p1("Carlos",18,'H');
    People p2("Maria",22,'F');
    People p3("Fernanda",21,'F');
    People p4("Jose",20,'H');
    People p5("Maria",22,'F');

    if(p5 == p2){
        cout<<"Holi somos iguales\n";
    }

    LinkedList<People> PeopleList;
    PeopleList.PushBack(p2);
    PeopleList.PushBack(p3);
    PeopleList.PushBack(p4);
    PeopleList.PushBack(p1);

    cout<<PeopleList;
}

int main(){
    Personas();
    return 0;
}