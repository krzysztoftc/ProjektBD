#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee : public Person
{
public:
    Employee();
    long superior;
    bool active;
    QString position;
};

#endif // EMPLOYEE_H
