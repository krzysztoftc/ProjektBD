#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person
{

public:
     Person();
     Person(long pesel, QString name, QString surname);

    long pesel;
    QString name;
    QString surname;

signals:

public slots:
};

#endif // PERSON_H
