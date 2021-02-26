/**
 * @file      Battleships.h
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Battleships game
 * @version   0.1
 * @date      25-02-2021
 * @copyright Copyright (c) 2021
 *
 */

#ifndef INC_BATTLESHIPS_H
#define INC_BATTLESHIPS_H

#include <windows.h>

#include <iostream>

class Battleships {
 public:
  /**
   * @brief     Construct a new Battleships object
   */
  Battleships() {
    for (size_t i{}; i < 10; ++i)
      for (size_t j{}; j < 10; ++j) field_[i][j] = '.';
  }

  /**
   * @brief     Destroy the Battleships object
   */
  ~Battleships() {}

  char getLocation(uint16_t& x, uint16_t& y) { return field_[x][y]; }

  /**
   * @brief     Print battlefield on the screen
   */
  void printField() const;

  /**
   * @brief     Filling in the battlefield
   * @param     field         battlefield
   */
  void fillField();

 private:
  // the game field
  char field_[10][10];

  // Coordinates on the field
  struct Coordinates {
    uint16_t x_, y_;
  };

  /**
   * @brief     Check valid coordinates.
   */
  void printErrorIndex() {
    std::cout << "\x1b[31mError: incorrect coordinates or this coordinates is "
                 "busy\x1b[37m\n";
    Sleep(600);
  }

  /**
   * @brief     Fill the single-deck ship
   * @param     coord         coordinates on the battlefield
   * @return    true          Coordinates is valid
   * @return    false
   */
  bool fillShip(const Coordinates& coord);

  /**
   * @brief     Fill the multi-decked ship
   * @param     begin         Coordinates of the begining of the ship
   * @param     end           Coordinates of the end of the ship
   * @param     shipSize      size of the ship type
   * @return    true          Coordinates is valid
   * @return    false
   */
  bool fillShip(const Coordinates& begin, const Coordinates& end,
                const uint16_t& shipSize);
};

#endif  // INC_BATTLESHIPS_H