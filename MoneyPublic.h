#ifndef MONEYPUBLIC_H
#define MONEYPUBLIC_H

#include "Money.h"

class MoneyPublic : public Money {
public:
    // Успадкування конструкторів базового класу
    using Money::Money;

    // Оператор присвоєння
    MoneyPublic& operator = (const MoneyPublic& other);

    // Унарні операції (змінюють об'єкт)
    MoneyPublic& operator ++ ();
    MoneyPublic operator ++ (int);
    MoneyPublic& operator -- ();
    MoneyPublic operator -- (int);

    friend MoneyPublic operator - (const MoneyPublic& a, const MoneyPublic& b);
    friend MoneyPublic operator * (const MoneyPublic& a, double factor);

    friend bool operator == (const MoneyPublic& a, const MoneyPublic& b);
    friend bool operator != (const MoneyPublic& a, const MoneyPublic& b);
    friend bool operator >  (const MoneyPublic& a, const MoneyPublic& b);
    friend bool operator <  (const MoneyPublic& a, const MoneyPublic& b);
    friend bool operator >= (const MoneyPublic& a, const MoneyPublic& b);
    friend bool operator <= (const MoneyPublic& a, const MoneyPublic& b);
};

#endif