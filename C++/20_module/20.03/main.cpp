/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задание 3. Реализация симуляции игры «Рыбалка».
 * Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки
 * (river.txt) задаётся список из видов рыб, которые можно в ней поймать. Рыбок
 * может быть сколько угодно, разных видов. Виды при этом могут повторяться.
 * В начале программы пользователь указывает, какую именно рыбу он сейчас будет
 * ловить — вид этой рыбы. После этого из первого файла друг за другом
 * осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах
 * вид совпал с указанным пользователем, в выходной файл basket.txt (корзинка)
 * записывается этот вид.
 * В конце программы показывается, сколько было поймано рыб за текущую ловлю.
 * Программу можно запускать несколько раз, при этом уже пойманные рыбы должны
 * сохраняться в файле-корзинке.
 * @version   0.1
 * @date      30-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "\x1b[2J";
  std::ifstream river("../river.txt");
  std::ofstream basket("../basket.txt", std::ios::app);
  if (!river || !basket) {
    cout << "Error: could not be opened!";
    return 1;
  }

  cout << "Enter the name of the fish you want to catch: ";
  std::string fishToCatch;
  cin >> fishToCatch;
  
  uint32_t nFishes{};
  while (river) {
    std::string fishInRiver;
    river >> fishInRiver;

    if (fishToCatch == fishInRiver) {
      basket << fishInRiver << "\n";
      ++nFishes;
    }
  }

  if (nFishes != 0)
    cout << "You caught " << nFishes << " fishes of " << fishToCatch;
  else
    cout << "You didn't catch any fish";

  river.close();
  basket.close();
  cout << "\x1b[0m" << endl;
  return 0;
}