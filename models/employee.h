#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include "person.h"

class Employee : public Person
{
public:
    Employee();
    long long superior;
    bool active;
    QString position;
};

#endif // EMPLOYEE_H
