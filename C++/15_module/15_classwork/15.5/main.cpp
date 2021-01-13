/** Поле чудес
Реализовать механизм открытия букв в игре “Поле чудес”. У вас имеется закрытое
слово из восьми букв “skillbox”, которое вы должны объявить в программе
константой. Игроки называют буквы посредством стандартного ввода. Если такая
буква есть в слове, она открывается в специальном массиве, на соответствующем
месте и весь массив выводится на экран, закрытые буквы при этом показываются как
прочерк “-”. Как только все прочерки исчезли, объявляется победа.
  */

#include <cstring>
#include <iostream>

int main() {
  const char *word{"skillbox"};
  // Размер слова.
  size_t sizeWord{std::strlen(word)};

  char result[sizeWord];
  // Заполняем результат '-'.
  for (int i{}; i < sizeWord; ++i) result[i] = '-';

  bool success{};
  while (!success) {
    char letter;
    std::cout << "Your letter: ";
    std::cin >> letter;

    for (int i{}; i < sizeWord; ++i)
      if (letter == word[i]) result[i] = letter;

    std::cout << "Word: " << result << "\n";
    success = true;

    for (int i{}; i < sizeWord; ++i) {
      if ('-' == result[i]) {
        success = false;
        break;
      }
    }
  }

  std::cout << "You did it!" << std::endl;

  getchar();
  getchar();

  return 0;
}