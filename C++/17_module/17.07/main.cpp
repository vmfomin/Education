/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 7. Пупырка.
 * После посылки из Китая осталась спец. плёнка для бережной перевозки груза —
 * пупырка. Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого
 * пузырька — это всегда либо он целый, либо нет, т.е. true или false (тип
 * массива bool). Для начала, требуется реализовать отдельную функцию
 * инициализации пупырки начальным состоянием — полностью целая пупырка, т.е.
 * все элементы true. Но это только самое начало.
 * Программа заключается в последовательном лопанье целых регионов пузырьков.
 * Перед каждым таким лопаньем надо показывать пользователю полностью всю
 * плёнку: o — это целый пузырёк, x — лопнутый. Это тоже надо выделить в
 * отдельную функцию. Итак, как выглядит само лопанье. Пользователь вводит две
 * координаты: координаты начала региона и конца прямоугольного региона. Сама
 * процедура лопанья пузырей должна быть реализована с помощью отдельной
 * функции, все аргументы должны проверяться на их валидность, что они в в
 * рамках диапазона возможных значений — иначе должна быть выведена ошибка.
 * После лопанья каждого пузыря, который не был ещё лопнут до того, в консоль
 * должно выводиться сообщение “Pop!”.
 * Лопанье должно продолжаться до последнего пузырька. Как только вся пупырка
 * потрачена, программа заканчивает выполнение. В принципе, вы можете подсчитать
 * окончание в самой функции по отображению пузырьков плёнки, т.к. она
 * выполняется после каждого лопанья.
 * @version   0.1
 * @date      15-02-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

/**
 * @brief     output of a vector of vectors to the console
 * @param     vec           vector of vectors of type bool
 * @return    true          all the bubbles were popped
 * @return    false
 */
bool outputVector(const std::vector<std::vector<bool>>& vec) {
  bool isPop{true};
  for (size_t i{}; i < vec.size(); ++i) {
    for (size_t j{}; j < vec.size(); ++j) {
      if (vec[i][j]) {
        std::cout << "\x1b[32mo ";
        isPop = false;
      } else {
        std::cout << "\x1b[33mx ";
      }
    }
    std::cout << "\n";
  }
  std::cout << "\x1b[37m\n";
  return isPop;
}

/**
 * @brief     Struct of coordinates.
 */
struct Coordinates {
  uint16_t x{}, y{};
};

/**
 * @brief     Check that the coordinates are correct
 * @param     coordinate    coordinates on the bubble wrap
 * @return    true          correct coordinates
 * @return    false
 */
inline bool checkCoordinates(struct Coordinates& coordinate) {
  if (coordinate.x > 11 || coordinate.y > 11) {
    std::cerr << "\x1b[31mError: index out of coordinates!\x1b[37m\n";
    return false;
  }
  return true;
}

int main() {
  std::cout << "\x1b[2J";
  std::vector<std::vector<bool>> bubbleWrap(12);
  for (size_t i{}; i < bubbleWrap.size(); ++i)
    for (size_t j{}; j < bubbleWrap.size(); ++j) bubbleWrap[i].push_back(true);

  do {
    std::cout << "\x1b[2JThe bubble wrap:\n";
    if (outputVector(bubbleWrap)) break;

    std::cout << "Which area do you want to pop?\n";
    Coordinates beginArea{};
    do {
      std::cout << "Enter begin of area (1 - 12): ";
      std::cin >> beginArea.x >> beginArea.y;
      --beginArea.x;
      --beginArea.y;
    } while (!checkCoordinates(beginArea));

    Coordinates endArea{};
    do {
      std::cout << "Enter end of area (1 - 12): ";
      std::cin >> endArea.x >> endArea.y;
      --endArea.x;
      --endArea.y;
    } while (!checkCoordinates(endArea));

    if (endArea.x - beginArea.x < 0 || endArea.y - beginArea.y < 0) {
      std::cerr << "\x1b[31mError: invalid coordinate range!\x1b[37m\n";
      continue;
    }

    for (size_t i{}; i < bubbleWrap.size(); ++i) {
      for (size_t j{}; j < bubbleWrap.size(); ++j) {
        if (i >= beginArea.x && i <= endArea.x && j >= beginArea.y &&
            j <= endArea.y)
          bubbleWrap[i][j] = false;
      }
    }

  } while (true);

  std::cout << "\x1b[36mYou popped all the bubbles\x1b[37m\n";

  return 0;
}