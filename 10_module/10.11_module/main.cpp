/// Задача 11. Треугольник Паскаля.
/// Напишите программу, которая выводит на экран N первых строк треугольника
/// Паскаля. N задаётся пользователем с клавиатуры. Треугольник Паскаля — это
/// числа, расположенные в виде треугольника, где по краям стоят единицы, а
/// каждое число внутри треугольника равно сумме двух чисел, расположенных над
/// ним. Обеспечьте контроль ввода.
/// Пример (N = 5):
///     1
///    1 1
///   1 2 1
///  1 3 3 1
/// 1 4 6 4 1

#include <iostream>

int main() {
    std::cout << "Введите количество 1 строк тругольника Паскаля: ";
    int16_t n{};
    std::cin >> n;
    std::cout << "\n";

    int16_t baseTriangle = n * 2; // Основание треугольника.
    int16_t centerTriangle = baseTriangle / 2;

    int pascal{};
    int firstPascal{1}, secondPascal{1}, temp{};
    int16_t countValue{}; // Счетчик значений в строке.

    for (int i = 0; i < n; i++) {
        // Высчитываю сколько должно быть # в строке
        int16_t inLineCount = i * 2 + 1;
        for (int j = 0; j < baseTriangle; j++) {
            if (j < centerTriangle - inLineCount || j > centerTriangle + inLineCount)
                std::cout << " ";
            else {
                if (countValue < inLineCount)
                    if (countValue == 0) {
                        firstPascal = 1;
                        std::cout << firstPascal;
                    } else if (countValue == inLineCount - 1) {
                        secondPascal = 1;
                        std::cout << secondPascal;
                    } else if (countValue % 2 != 0) {
                        firstPascal = secondPascal;
                        secondPascal = pascal;
                        std::cout << " ";
                    } else {
                        std::cout << pascal;
                    }
                else {
                    pascal = firstPascal + secondPascal;
                    std::cout << " ";
                }
                countValue++;
            }
        }
        countValue = 0;
        centerTriangle++;
        std::cout << "\n";
    }

    return 0;
}