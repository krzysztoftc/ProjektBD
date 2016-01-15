#include "person.h"

Person::Person(long long pesel, QString name, QString surname)
{
    this->pesel = pesel;
    this->name = name;
    this->surname = surname;
}

Person::Person(){
    this->pesel = 0;
    this->name = "";
    this->surname = "";
}
