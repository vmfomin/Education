/**
 * @file      Battleships.h
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     The battleships game main class
 * @version   0.1
 * @date      09-03-2021
 * @copyright Copyright (c) 2021
 */

#ifndef INC_BATTLESHIPS_H
#define INC_BATTLESHIPS_H

#include "BattleshipsAdd.h"

class Battleships {
 public:
  /**
   * @brief     Construct a new Battleships game object
   */
  Battleships() {
    for (size_t i{}; i < 10; ++i) {
      for (size_t j{}; j < 10; ++j) {
        playerScreenOne_[i][j] = '.';
        playerScreenTwo_[i][j] = '.';
      }
    }
  }

  /**
   * @brief     Destroy the Battleships game object
   */
  virtual ~Battleships() {}

  /**
   * @brief     launch of the sea battle game
   */
  void launchBattle();

 private:
  /**
   * @brief     location of player ships
   */
  BattleshipsAdd playerOne_;
  BattleshipsAdd playerTwo_;

  /**
   * @brief     undefined fields before battle
   */
  char playerScreenOne_[10][10];
  char playerScreenTwo_[10][10];

  /**
   * @brief     printing the game screen
   * @param     odd           whose move
   */
  void printScreen(const uint16_t& odd);

  /**
   * @brief     shooting routine
   * @param     player        location of player ships
   * @param     playerScreen  undefined fields before battle
   * @param     nShoots       count of shoots for each player
   */
  void shoot(BattleshipsAdd& player, char playerScreen[10][10],
             uint16_t& nShoots);
};

#endif  // INC_BATTLESHIPS_H