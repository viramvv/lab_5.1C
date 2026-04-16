#include "MoneyPublic.h"

// Присвоєння
MoneyPublic& MoneyPublic::operator=(const MoneyPublic& other) {
    if (this != &other) {
        setHryvnia(other.getHryvnia());
        setKopeks(other.getKopeks());
    }
    return *this;
}

// Інкремент ++
MoneyPublic& MoneyPublic::operator++() {
    long total = getHryvnia() * 100 + getKopeks() + 1;
    setHryvnia(total / 100);
    setKopeks(total % 100);
    return *this;
}

MoneyPublic MoneyPublic::operator++(int) {
    MoneyPublic temp = *this;
    ++(*this);
    return temp;
}

// Декремент --
MoneyPublic& MoneyPublic::operator--() {
    long total = (long)getHryvnia() * 100 + getKopeks() - 1;
    if (total < 0) throw MoneyException("Сума не може бути від'ємною!");
    setHryvnia(total / 100);
    setKopeks(total % 100);
    return *this;
}

MoneyPublic MoneyPublic::operator--(int) {
    MoneyPublic temp = *this;
    --(*this);
    return temp;
}

// Віднімання
MoneyPublic operator - (const MoneyPublic& a, const MoneyPublic& b) {
    long long t1 = (long long)a.getHryvnia() * 100 + a.getKopeks();
    long long t2 = (long long)b.getHryvnia() * 100 + b.getKopeks();
    if (t1 < t2) throw MoneyException("Результат віднімання від'ємний!");
    long long res = t1 - t2;
    return MoneyPublic(res / 100, (unsigned char)(res % 100));
}

// Множення
MoneyPublic operator * (const MoneyPublic& a, double factor) {
    if (factor < 0) throw MoneyException("Множник не може бути від'ємним!");
    long long res = (long long)((a.getHryvnia() * 100 + a.getKopeks()) * factor);
    return MoneyPublic(res / 100, (unsigned char)(res % 100));
}

// Порівняння
bool operator == (const MoneyPublic& a, const MoneyPublic& b) {
    return a.getHryvnia() == b.getHryvnia() && a.getKopeks() == b.getKopeks();
}

bool operator != (const MoneyPublic& a, const MoneyPublic& b) { return !(a == b); }

bool operator > (const MoneyPublic& a, const MoneyPublic& b) {
    return (a.getHryvnia() > b.getHryvnia()) ||
           (a.getHryvnia() == b.getHryvnia() && a.getKopeks() > b.getKopeks());
}

bool operator < (const MoneyPublic& a, const MoneyPublic& b) { return b > a; }
bool operator >= (const MoneyPublic& a, const MoneyPublic& b) { return !(a < b); }
bool operator <= (const MoneyPublic& a, const MoneyPublic& b) { return !(a > b); }