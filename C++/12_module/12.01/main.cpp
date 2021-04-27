/* Задача 1. Корабли в “морском бое”
Требуется объявить массивы для игры в морской бой и вывести их размеры в
консоль, не используя констант с размерами. Всего таких типов 4: крошечный,
малый, средний и большой. Для простоты, типом элементов корабля могут быть
обычные bool (размер 1 байт). */

#include <iostream>

/**
 * @brief  Вывод в консоль размера корабля.
 * @note   Использовал const, чтобы нельзя было изменить значение в ссылке.
 * Ссылку применил, чтобы не было копирования переменной в функцию.
 * @param  &sizeStr: строка с размером массива.
 * @param  &size: размер массива.
 */
inline void printSize(const std::string &sizeStr, const int &size) {
  std::cout << "The size of " << sizeStr << "\tship in the battle is " << size
            << "\n";
}

int main() {
  std::string sizes[]{"tiniest", "smallest", "middle", "largest"};
  
  bool tinyShip[]{true};
  // Если bool, то можно деление на первый элемент массива убрать, т.к. тип bool
  // равен 1 байту. Но тут решил оставить, мало ли какой тип будет.
  printSize(sizes[0], sizeof(tinyShip) / sizeof(tinyShip[0]));

  bool smallShip[]{true, true};
  printSize(sizes[1], sizeof(smallShip) / sizeof(smallShip[0]));

  bool mediumShip[]{true, true, true};
  printSize(sizes[2], sizeof(mediumShip) / sizeof(mediumShip[0]));

  bool largestShip[]{true, true, true, true};
  printSize(sizes[3], sizeof(largestShip) / sizeof(largestShip[0]));

  return 0;
}
