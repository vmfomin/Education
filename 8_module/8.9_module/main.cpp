/// Задача 9. Треугольник на координатной плоскости.
/// Проверьте, образуют ли треугольник три данные точки на координатной плоскости. Каждая точка задается двумя
/// координатами. Таким образом, на вход программе дается 6 чисел: координаты первой точки, затем координаты второй точки
/// и координаты третьей точки. Программа должна ответить “Yes”, если три данные точки задают треугольник, и “No” иначе.
/// Например, если хотя бы две из данных точек совпадают, то треугольника данные три точки не образуют. Другой пример:
/// точки с координатами (1; 2), (3; 6) и (-2; -4) не образуют треугольника, поскольку они лежат на одной прямой,
/// хоть и не совпадают.
/// Подсказка. Три точки А, B и С будут лежать на одной прямой, если совпадают углы наклона прямых, проведенных через
/// любые две пары точек (например, совпадают прямые АВ и ВС).
/// Угол можно проверить с помощью формулы (a-x)/(b-y), где a и b — координаты первой точки, а x и y — координаты второй.

#include <iostream>

// Решил сделать структуру, так будет проще работать. Массив структур решил не делать, читаться будет сложнее.
struct Point {
    int x;
    int y;
}; // point[3]; Например, так можно было добавить

int main() {
    // Иницилизировал точки нулями, чтобы не было мусора.
    Point a{}, b{}, c{};

    std::cout << "Введите точку A: ";
    std::cin >> a.x >> a.y;

    std::cout << "Введите точку B: ";
    std::cin >> b.x >> b.y;

    std::cout << "Введите точку C: ";
    std::cin >> c.x >> c.y;

    // Важно для знаменателя, т.к. там будет деление на 0.
    if (a.x == b.x || a.x == c.x || b.x == c.x || a.y == b.y || a.y == c.y || b.y == c.y) {
        std::cout << "Координаты должны быть разными!\n";
        return -1;
    }

    int ab = (a.x - b.x) / (a.y - b.y);
    int ac = (a.x - c.x) / (a.y - c.y);
    int bc = (b.x - c.x) / (b.y - c.y);

    std::cout << (ab == bc || ab == ac || ac == bc ? "No\n" : "Yes\n");

    return 0;
}
