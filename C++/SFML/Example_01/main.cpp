/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     SFML project
 * @version   0.1
 * @date      10-03-2021
 * @copyright Copyright (c) 2021
 */

#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed) window.close();
    window.clear(sf::Color(250, 200, 100, 0));
    window.display();
  }

  return 0;
}