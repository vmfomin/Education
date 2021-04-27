/**
 * @file      TicTacToe.h
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     The TicTacToe game
 * @version   0.1
 * @date      11-02-2021
 * @copyright Copyright (c) 2021
 */

#ifndef INC_TIC_TAC_TOE_H
#define INC_TIC_TAC_TOE_H

#include <iostream>

/**
 * @brief     The tic-tac-toe game class
 */
class TicTacToe {
 public:
  /**
   * @brief     Construct a new Tic Tac Toe object.
   * Initialization of the field for the game Tic tac toe
   */
  TicTacToe() {
    for (size_t i{}; i < 3; ++i)
      for (size_t j{}; j < 3; ++j) tictactoe_[i][j] = '.';
  }

  /**
   * @brief     Destroy the Tic Tac Toe object
   */
  virtual ~TicTacToe() {}

  /**
   * @brief     Start the tic-tac-toe game
   */
  void start();

 private:
  char tictactoe_[3][3];  // The playing field.

  /**
   * @brief     displaying the field on the screen
   */
  void printField() {
    for (size_t i{}; i < 3; ++i) {
      for (size_t j{}; j < 3; ++j) std::cout << tictactoe_[i][j] << " ";
      std::cout << "\n";
    }
    std::cout << "\n";
  }

  /**
   * @brief     Enter the position on the field
   * @param     count         if the number is odd, then crosses are move
   */
  void inputPosition(size_t& count);

  /**
   * @brief     Check the condition of winning
   * @return    true          a winner is found
   * @return    false         nobody won
   */
  bool check();
};

#endif  // INC_TIC_TAC_TOE_H