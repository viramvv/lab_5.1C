#include <iostream>
#include "MoneyPublic.h"

int main() {
    try {
        MoneyPublic m1;
        std::cout << "Ввід m1 через Read() (використовує сетери):" << std::endl;
        m1.Read();

        MoneyPublic m2("5,50"); // Конструктор рядка

        std::cout << "\nВивід через оператор << (використовує toString):" << std::endl;
        std::cout << "m1: " << m1 << std::endl;
        std::cout << "m2: " << m2 << std::endl;

        std::cout << "\nРезультат m1 - m2: " << (m1 - m2) << std::endl;

        std::cout << "\nПеревірка всіх порівнянь:" << std::endl;
        std::cout << "m1 == m2: " << (m1 == m2) << std::endl;
        std::cout << "m1 != m2: " << (m1 != m2) << std::endl;
        std::cout << "m1 > m2:  " << (m1 > m2) << std::endl;
        std::cout << "m1 < m2:  " << (m1 < m2) << std::endl;
        std::cout << "m1 >= m2: " << (m1 >= m2) << std::endl;
        std::cout << "m1 <= m2: " << (m1 <= m2) << std::endl;

    } catch (const MoneyException& e) {
        std::cerr << "\nПОМИЛКА: " << e.what() << std::endl;
    }

    return 0;
}