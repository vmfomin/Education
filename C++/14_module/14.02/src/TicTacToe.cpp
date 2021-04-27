/**
 * @file      TicTacToe.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     The TicTacToe game
 * @version   0.1
 * @date      11-02-2021
 * @copyright Copyright (c) 2021
 */

#include "TicTacToe.h"

void TicTacToe::start() {
  bool victory;     // Check the victory
  size_t count{1};  // Number of moves in the game
  do {
    std::cout << "\x1b[2J\x1b[36mWelcome to the tic-tac-toe game:\x1b[32m\n";
    printField();
    inputPosition(count);

    if (count >= 5) {
      victory = check();
      if (victory) break;
    }
    ++count;
  } while (count <= 9);

  // Results
  std::cout << "\x1b[2J";
  if (victory) {
    std::cout << "\x1b[36mCongrats!\x1b[32m\n";
    printField();
    std::cout << "\x1b[33m\n";
    std::cout << (count % 2 != 0 ? "\"X\" won!\n" : "\"O\" won!\n");
  } else {
    std::cout << "\x1b[36mUnfortunately\x1b[32m\n";
    printField();
    std::cout << "\x1b[33mNobody won\n";
  }
  std::cout << "\x1b[37m\n";
}

void TicTacToe::inputPosition(size_t& count) {
  do {
    std::cout << "\x1b[37m\n";
    std::cout << (count % 2 != 0 ? "\"X\" moves\n" : "\"O\" moves\n");
    std::cout << "Enter the position on the field (from 1 to 3 to each "
                 "index): \x1b[32m";
    uint16_t posX, posY;
    std::cin >> posX >> posY;
    --posX;
    --posY;
    if (posX > 2 || posY > 2) {
      std::cout << "\x1b[31mIncorrect indexes\x1b[37m\n";
      continue;
    }

    if ('.' == tictactoe_[posX][posY]) {
      count % 2 != 0 ? tictactoe_[posX][posY] = 'X'
                     : tictactoe_[posX][posY] = 'O';
      break;
    } else {
      std::cout << "\x1b[31mIncorrect: this location is busy\x1b[37m\n";
      continue;
    }
  } while (true);
}

bool TicTacToe::check() {
  // Check diagonal won
  if (tictactoe_[0][0] != '.' && tictactoe_[0][0] == tictactoe_[1][1] &&
          tictactoe_[0][0] == tictactoe_[2][2] ||
      tictactoe_[0][2] != '.' && tictactoe_[0][2] == tictactoe_[1][1] &&
          tictactoe_[0][2] == tictactoe_[2][0]) {
    return true;
  }

  for (size_t i{}; i < 3; ++i) {
    // Horizontal and vertical check in the loop
    uint16_t horizontalCheck{}, verticalCheck{};

    char h{tictactoe_[i][0]};  // horizontal temp
    char v{tictactoe_[0][i]};  // vertical temp
    for (size_t j{1}; j < 3; ++j) {
      if (h != '.' && h == tictactoe_[i][j]) ++horizontalCheck;
      if (v != '.' && v == tictactoe_[j][i]) ++verticalCheck;
    }
    if (2 == horizontalCheck || 2 == verticalCheck) return true;
  }
  return false;
}
