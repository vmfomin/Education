/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 2.
 * С помощью списка инициализации задаётся вектор цен на продукты (дробными
 * числами). Так же, с помощью списка инициализации, задаётся вектор покупок (в
 * виде индексов), которые совершает человек. Необходимо вывести на экран
 * итоговую стоимость покупок
 * Пример:
 * Вектор цен выглядит так: {2.5, 4.25, 3.0, 10.0}
 * Вектор покупок: {1, 1, 0, 3}, то есть два товара по индексу 1, и по одному —
 * индексов 0 и 3.
 * Суммарная стоимость будет равна 21.0
 * @version 0.1
 * @date 22-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::vector<float> prices{2.5f, 4.25f, 3.0f, 10.0f};
  std::cout << "\e[2JPrices:   \e[32m";
  for (const auto& price : prices) std::cout << price << " ";

  std::cout << "\e[0m\n";  // Сброс цвета перевод коретки.

  std::vector<int> purchases{1, 1, 0, 3};
  std::cout << "Purchase: \e[32m";
  for (const auto& purchase : purchases) std::cout << purchase << " ";

  float sum{};
  for (const auto& i : purchases) sum += prices[i];

  std::cout << "\n\e[36mPurchase amount: " << sum << "\e[0m\n";

  return 0;
}