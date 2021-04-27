/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 5.
 * В начале каждого хода игроки вращают волчок, то есть выбирают сектор на
 * столе, который сейчас играет. Всего таких секторов 13. Сектор выбирается так:
 * с клавиатуры вводится офсет (смещение) относительно текущего сектора на
 * барабане. Исходя из этого офсета вычисляется новый активный сектор, который и
 * будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий
 * неигравший за ним.
 * В начале всей игры стрелка установлена на первом секторе. Как только играет
 * какой-то из секторов, с него берётся письмо с вопросом — то есть считывается
 * из файла данного сектора. Вопрос показывается на экране.
 * После того как вопрос показан, от игрока ожидается ответ на него. Игрок
 * вводит этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается
 * с ответом, который хранится во втором файле, ассоциированном с активным
 * сектором. Данный файл должен содержать лишь одно слово-ответ.
 * Если ответ знатока-игрока был правильным, ему начисляется один балл. Если
 * неверен, то балл уходит телезрителям.
 * Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть
 * баллов. После этого называется победитель и программа заканчивает работу.
 * @version   0.1
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <windows.h>

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;

int main() {
  std::ifstream questionsFile("../questions.txt");
  std::ifstream answersFile("../answers.txt");
  if (!questionsFile || !answersFile) {
    cout << "Error: couldn't open for reading!\n";
    return 1;
  }

  bool sectors[13]{};
  for (auto &i : sectors) i = true;

  uint16_t nExperts{}, nTvViewers{};
  while (true) {
    cout << "\x1b[2JEnter a sector of quetions (1 - 13): ";
    int16_t sector;
    cin >> sector;
    --sector;
    if (sector < 0 || sector > 12) {
      cout << "Error index of sector!\n";
      continue;
    }

    if (12 == sector && !sectors[sector]) sector = 0;
    for (int16_t i{sector}; i < 13; ++i) {
      if (sectors[i]) {
        sector = i;
        break;
      } else if (12 == i) {
        i = -1;
      }
    }

    std::string question{};
    std::string answer{};
    for (uint16_t i{}; i <= sector; ++i) {
      std::getline(questionsFile, question);
      std::getline(answersFile, answer);
    }

    {
      cout << question << std::endl;
      cout << "Enter your answer: ";
      std::string expertAnswer;
      cin >> expertAnswer;
      if (expertAnswer == answer) {
        cout << "\nThe Experts are right. The score goes to them.\n";
        ++nExperts;
      } else {
        cout << "\nThe Experts are wrong. The score goes to TV viewers.\n";
        cout << "Correct answer: " << answer << "\n";
        ++nTvViewers;
      }
      cout << "\nCurrent score is " << nExperts << ":" << nTvViewers << std::endl;
      Sleep(1900);
      sectors[sector] = false;
      questionsFile.seekg(std::ios::beg);
      answersFile.seekg(std::ios::beg);
    }

    if (6 == nExperts) {
      cout << "\n\x1b[36mThe experts won with a score of " << nExperts << ":"
           << nTvViewers;
      break;
    }
    if (6 == nTvViewers) {
      cout << "\n\x1b[36mThe TV viewers won with a score of " << nTvViewers
           << ":" << nExperts;
      break;
    }
  }

  questionsFile.close();
  answersFile.close();
  cout << "\x1b[0m" << std::endl;
  return 0;
}