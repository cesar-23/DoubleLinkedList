#ifndef __PEOPLE__H__
#define __PEOPLE__H__

#include <string>
#include <iostream>

class People{
    private:
        std::string name;
        int age;
        char sex;
    public:
        People();
        People(std::string, int, char);
        People(const People&);
        People(People &&);
        ~People();

        People operator =(const People&);
        People operator =(const People&&);
        bool operator ==(const People&)const;

        friend std::ostream &operator << (std::ostream &out, const People &o){
            out<<"Sujeto: \n";
            out<<"Nombre:\t"<<o.name<<"\n";
            out<<"Edad:\t"<<o.age<<"\n";
            out<<"Sexo:\t"<<o.sex<<"\n";
            return out;
        }
};

People::People(){
    this->name = "0";
    this->age = 0;
    this-> sex = '0';
}

People::People(std::string _name, int _age, char _sex){
    this->name = _name;
    this->age = _age;
    this->sex = _sex;
}

People::People(const People&o){
    this->name=o.name;
    this->age=o.age;
    this->sex=o.sex;
}

People::People(People &&o){
    this->name=o.name;
    this->age=o.age;
    this->sex=o.sex;
}

People::~People(){}

People People::operator =(const People &o){
    this->name=o.name;
    this->age=o.age;
    this->sex=o.sex;
    return *this;
}

People People::operator =(const People &&o){
    this->name=o.name;
    this->age=o.age;
    this->sex=o.sex;
    return *this;
}

bool People::operator ==(const People &o) const{
    return this->name == o.name && this->age == o.age && this->sex==o.sex;
}

#endif