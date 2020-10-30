/// Задача 5. Повышаем градус сложности

#include <iostream>
#include <functional>

int main() {

    int a = -100;
    int b = 2000;

    std::cout << "До обмена местами\n";
    std::cout << "a: " << a << "\n"
              << "b: " << b << "\n";

    a += b;
    b = a - b;
    a -= b;

    std::cout << "После обмена местами\n";
    std::cout << "a: " << a << "\n"
              << "b: " << b << "\n";

    a = 20;
    b = 30;

    std::cout << "\nДо обмена местами XOR\n"
              << "Работает только с типом int, float не работает.\n";
    std::cout << "a: " << a << "\n"
              << "b: " << b << "\n";

    a ^= b ^= a ^= b;

    std::cout << "После обмена местами XOR\n";
    std::cout << "a: " << a << "\n"
              << "b: " << b << "\n";

    float aSwap = 7.3;
    float bSwap = 3.5;

    std::cout << "\nДо обмена местами SWAP\n";
    std::cout << "aSwap: " << aSwap << "\n"
              << "bSwap: " << bSwap << "\n";

    std::swap(bSwap, aSwap);

    std::cout << "После обмена местами методом SWAP\n";
    std::cout << "aSwap: " << aSwap << "\n"
              << "bSwap: " << bSwap << "\n";

    float aTie = 10.11;
    float bTie = 20.47;

    std::cout << "\nДо обмена местами Tie\n";
    std::cout << "aTie: " << aTie << "\n"
              << "bTie: " << bTie << "\n";
    std::tie(aTie, bTie) = std::make_pair(bTie, aTie);

    std::cout << "После обмена местами методом tie\n";
    std::cout << "aTie: " << aTie << "\n"
              << "bTie: " << bTie << "\n";

    return 0;
}
