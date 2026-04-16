#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>
#include <stdexcept>

// Клас винятку для обробки помилок (наприклад, від'ємні копійки)
class MoneyException : public std::runtime_error {
public:
    MoneyException(const std::string& msg) : std::runtime_error(msg) {}
};

class Money {
private:
    long hryvnia;
    unsigned char kopeks;

public:
    Money();
    Money(long h, unsigned char k);
    Money(const std::string& str);
    Money(const Money& other);

    long getHryvnia() const { return hryvnia; }
    unsigned char getKopeks() const { return kopeks; }

    void setHryvnia(long h);
    void setKopeks(unsigned char k);

    bool Init(long h, unsigned char k);
    void Read();
    void Display() const;
    std::string toString() const;

    friend std::ostream& operator << (std::ostream& out, const Money& m);
    friend std::istream& operator >> (std::istream& in, Money& m);
};

#endif // MONEY_H