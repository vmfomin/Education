/// Задача 3. Обмен местами

#include <iostream>

int main() {
    int a = 7;
    int b = 3;
    int temp;

    std::cout << "До обмена местами\n";
    std::cout << "a: " << a << "\n"
              << "b: " << b << "\n";

    temp = a;
    a = b;
    b = temp;

    std::cout << "\nПосле обмена местами\n";
    std::cout << "a: " << a << "\n"
              << "b: " << b << "\n";

    return 0;
}