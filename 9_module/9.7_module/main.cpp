/// Задача 7. Числа Фибоначчи.
/// Числами Фибоначчи называется следующая последовательность чисел: 1, 1, 2, 3,
/// 5, 8, 13 и так далее (первое число равно 1, второе число равно 1, а каждое
/// следующее равно сумме двух предыдущих). Напишите программу, которая по данному
/// номеру N выводит N-е число этой последовательности (если оно не превосходит
/// 2147483647, конечно же). Обеспечьте контроль ввода.

#include <iostream>

int main() {
    int n, fibonacci;
    int fibonacciFirst = 1, fibonacciSecond = 1;

    std::cout << "N-число последовательности: ";
    std::cin >> n;
    if (n > 2147483647) {
        std::cout << "N-число не может быть больше 2147483647 (максимум int)!\n"
                  << "N-число последовательности: ";
        std::cin >> n;
    }

    std::cout << fibonacciFirst << " " << fibonacciSecond << " ";

    // Счетчик. Начинаю с 2, т.к. изначально вывожу 2 цифры.
    int count = 2;

    while (count < n) {
        fibonacci = fibonacciFirst + fibonacciSecond;

        std::cout << fibonacci << " ";

        fibonacciFirst = fibonacciSecond;
        fibonacciSecond = fibonacci;

        count++;
    }

    std::cout << "\n";

    return 0;
}
