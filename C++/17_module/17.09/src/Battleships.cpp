/**
 * @file      Battleships.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     The battleships game main class
 * @version   0.1
 * @date      09-03-2021
 * @copyright Copyright (c) 2021
 */

#include "Battleships.h"

void Battleships::launchBattle() {
  std::cout << "\x1b[2JThe first player will fill their battlefield:\n";
  playerOne_.fillField();
  std::cout << "\x1b[2JThe first player's battlefield:\n";
  playerOne_.printField();

  std::cout << "\x1b[2JThe second player will fill their battlefield:\n";
  playerTwo_.fillField();
  std::cout << "The second player's battlefield:\n";
  playerTwo_.printField();

  uint16_t countOne{}, countTwo{}, odd{};
  while (true) {
    if ((odd & 1) == 1) {
      std::cout << "\x1b[2J\t\t\t   First player's move\n";
      printScreen(odd);
      shoot(playerTwo_, playerScreenTwo_, countOne);
    } else {
      std::cout << "\x1b[2J\t\t\t  Second player's move\n";
      printScreen(odd);
      shoot(playerOne_, playerScreenOne_, countTwo);
    }

    if (20 == countOne) {
      std::cout << "\x1b[2J";
      printScreen(odd);
      std::cout << "\n\x1b[36mThe first player won!\x1b[37m\n";
      break;
    } else if (20 == countTwo) {
      std::cout << "\x1b[2J";
      printScreen(odd);
      std::cout << "\n\x1b[36mThe second player won!\x1b[37m\n";
      break;
    }
    ++odd;
  }
}

void Battleships::printScreen(const uint16_t& odd) {
  std::cout
      << ((odd & 1) == 1
              ? "\x1b[31m\t    Player one\x1b[37m\t\t\t\t    Player two\n"
              : "\t    Player one\t\t\t\t    \x1b[31mPlayer two\n\x1b[37m");
  std::cout << "\n";
  for (size_t i{}; i < 10; ++i) {
    if (0 == i) {
      std::cout << "   ";
      for (size_t j{}; j < 10; ++j) std::cout << j << "  ";
      std::cout << "  ||\t    ";
      for (size_t j{}; j < 10; ++j) std::cout << j << "  ";
      std::cout << "\n";
    }
    std::cout << i << "  ";
    for (size_t j{}; j < 10; ++j) std::cout << playerScreenOne_[i][j] << "  ";
    std::cout << "  ||    " << i << "  ";

    for (size_t j{}; j < 10; ++j) std::cout << playerScreenTwo_[i][j] << "  ";
    std::cout << "\n";
  }
  std::cout << "\n";
}

void Battleships::shoot(BattleshipsAdd& player, char playerScreen[10][10],
                        uint16_t& nShoots) {
  do {
    std::cout << "Enter the coordinates to shoot: ";
    uint16_t x, y;
    std::cin >> x >> y;
    if (x > 9 || y > 9) {
      std::cout << "\x1b[31mError: incorrect coordinates!\x1b[37m\n";
      continue;
    }

    if ('o' == player.getLocation(x, y) && playerScreen[x][y] != 'x') {
      playerScreen[x][y] = 'x';
      std::cout << "\x1b[32mYou hit him!\x1b[37m\n";
      Sleep(350);
      ++nShoots;
      break;
    } else if ('*' == playerScreen[x][y] || 'x' == playerScreen[x][y]) {
      std::cout << "\x1b[31mYou've already shot at this place!\x1b[37m\n";
      continue;
    } else {
      playerScreen[x][y] = '*';
      std::cout << "You missed it!\n";
      Sleep(350);
      break;
    }
  } while (true);
}