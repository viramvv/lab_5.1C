#include "Money.h"
#include <iomanip>
#include <sstream>

// 1. Конструктори
Money::Money() : hryvnia(0), kopeks(0) {}

Money::Money(long h, unsigned char k) {
    setHryvnia(h);
    setKopeks(k);
}

Money::Money(const Money& other) : hryvnia(other.hryvnia), kopeks(other.kopeks) {}

Money::Money(const std::string& str) {
    size_t comma = str.find(',');
    if (comma == std::string::npos) throw MoneyException("Формат має бути 'ГРН,КОП'");
    setHryvnia(std::stol(str.substr(0, comma)));
    setKopeks((unsigned char)std::stoi(str.substr(comma + 1)));
}

// 2. Сетери (збудовані на логіці винятків)
void Money::setHryvnia(long h) {
    if (h < 0) throw MoneyException("Гривні не можуть бути від'ємними!");
    hryvnia = h;
}

void Money::setKopeks(unsigned char k) {
    if (k >= 100) throw MoneyException("Копійки мають бути в межах 0-99!");
    kopeks = k;
}

// 3. Методи введення/виведення
bool Money::Init(long h, unsigned char k) {
    if (h < 0 || k >= 100) return false;
    hryvnia = h; kopeks = k;
    return true;
}

// Реалізація методу Read, якого не вистачало для LabRun
void Money::Read() {
    long h;
    int k;
    bool success = false;

    do {
        std::cout << "Введіть суму:" << std::endl;
        std::cout << "  Гривні: "; std::cin >> h;
        std::cout << "  Копійки: "; std::cin >> k;

        try {
            setHryvnia(h);
            setKopeks((unsigned char)k);
            success = true;
        } catch (const MoneyException& e) {
            std::cout << "Помилка: " << e.what() << " Спробуйте ще раз." << std::endl;
        }
    } while (!success);
}

std::string Money::toString() const {
    std::stringstream ss;
    ss << hryvnia << "," << std::setfill('0') << std::setw(2) << (int)kopeks;
    return ss.str();
}

void Money::Display() const {
    std::cout << "Сума: " << toString() << " грн." << std::endl;
}

// 4. Перевантаження операторів потоків
std::ostream& operator << (std::ostream& out, const Money& m) {
    out << m.toString();
    return out;
}

std::istream& operator >> (std::istream& in, Money& m) {
    long h; int k;
    in >> h >> k;
    m.setHryvnia(h);
    m.setKopeks((unsigned char)k);
    return in;
}