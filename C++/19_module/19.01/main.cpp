/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 1.
 * Составьте небольшой текстовый файл «words.txt», в котором последовательно,
 * через пробелы и переносы строк расположены различные слова. Можете
 * использовать любые англоязычные слова. Разработайте программу, которая искала
 * бы среди этих слов нужное пользователю и выводила бы общее количество
 * повторений этого слова. 0 — если слово вообще не присутствует в файле.
 * @version   0.1
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;

int main() {
  cout << "\x1b[2J";
  std::ifstream wordsFile("../words.txt");
  if (!wordsFile) {
    cout << "Error: could not be opened for reading!";
    return 1;
  }

  cout << "Enter a search word: ";
  std::string searchWord{};
  cin >> searchWord;

  int16_t nWords{};
  while (wordsFile) {
    std::string word;
    wordsFile >> word;
    if (word == searchWord) ++nWords;
  }

  cout << "The search word \"" << searchWord << "\" was found " << nWords
       << " times" << std::endl;

  wordsFile.close();
  cout << std::endl;
  return 0;
}