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

// Вычисление биномиального коэффициента.
double cnk(int n, int k) {
    double pascal{1};
    for (int i = 1; i <= k; i++)
        pascal *= static_cast<float>(n - i + 1) / static_cast<float>(i);

    return pascal;
}

int main() {
    std::cout << "Введите количество 1 строк тругольника Паскаля: ";
    int16_t n{};
    std::cin >> n;
    std::cout << "\n";

    int16_t baseTriangle = n * 2; // Основание треугольника.
    int16_t centerTriangle = baseTriangle / 2;

    int16_t countValue{}; // Счетчик значений в строке.

    for (int i = 0; i < n; i++) {
        // Высчитываю сколько должно быть # в строке
        int16_t inLineCount = i + 1;
        for (int j = 0; j < baseTriangle; j++) {
            if (j < centerTriangle - inLineCount || j > centerTriangle + inLineCount)
                std::cout << " ";
            else {
                if (countValue < inLineCount) {
                    std::cout << cnk(i, countValue) << " ";
                    countValue++;
                }
            }
        }
        countValue = 0;
        std::cout << "\n";
    }

    return 0;
}