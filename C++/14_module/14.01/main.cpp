/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 1. Банкетный стол
 * По поводу успешного прохождения двумерных массивов собирается банкет,
 * организуется стол на 12 персон, 2 из них - это места VIP, они расположены
 * рядом друг к другу во главе стола. Стол протяжённый в длину, места
 * расположены в два ряда. Каждый пришедший должен быть “упакован”
 * соответствующим образом. Во-первых столовые приборы - их три на каждого
 * человека (вилка, ложка, нож), плюс одна маленькая дополнительная ложечка для
 * VIP-персон, для десерта. Это необходимо обеспечить. Следом тарелки, каждому
 * по две - для первого и второго блюда, для VIP персон +1 тарелка для десерта.
 * Ну и конечно стул - один для каждого, минимум! Заведите соответствующие
 * двумерные массивы для количества приборов, посуды и стульев и
 * проинициализируйте их как следует. Однако, это ещё не всё. В ходе банкета,
 * уже после инициализации, происходят некоторые события. Пришедшая на 5-ое
 * место первого ряда дама пришла вместе с ребёнком и поэтому на данное место
 * был приставлен ещё один стул. С третьего места во втором ряду в неизвестном
 * направлении была украдена ложка. После этого одна из VIP персон (любая)
 * поделилась своей ложкой с тем у кого она пропала, а сам стал есть суп
 * десертной. За ненадобностью официант забрал у него одну десертную тарелку,
 * ибо есть десерт ложкой, которая побывала уже в супе - не комильфо. Больше без
 * происшествий!
 * @version   0.1
 * @date      10-02-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <iterator>
#include <vector>

/**
 * @brief     Print seating guests at the table
 * @param     serve         tableware for guests
 */
void printServe(const std::vector<std::vector<std::string>>& serve) {
  for (auto it{serve.begin()}; it != serve.end(); ++it) {
    if (it - serve.begin() == 0)
      std::cout << "\x1b[37mVIP serve:\x1b[32m\n";
    else if (it - serve.begin() == 2)
      std::cout << "\x1b[37mFirst part of the table:\x1b[32m\n";
    else if (it - serve.begin() == 7)
      std::cout << "\x1b[37mSecond part of the table:\x1b[32m\n";
    // Использовал такой вид записи. Можно обычной индексацией без итераторов,
    // но уже как-то привык к итераторам. Увидел запись вложенного цикла на
    // итераторах, где применяется std::distance, которая вложена в at(). Это
    // ужас. До этого видел такую запись вывода в консоль (в классных задачах
    // даже использовал). Удобна запись тем, что кидает в буфер без лишних
    // итераций. Ну и в целом удобная запись копирования контейнеров.
    // (откуда.начало, откуда.конец, куда). чем-то напоминает memcpy из Си.
    std::copy(it->begin(), it->end(),
              std::ostream_iterator<std::string>(std::cout, "  "));
    std::cout << "\n";
  }
  std::cout << "\n";
}

int main() {
  std::cout << "\x1b[2J";

  std::vector<std::vector<std::string>> serve{
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair",
       "dessert plate", "dessert spoon"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair",
       "dessert plate", "dessert spoon"},
      // 1 part of the table
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      // 2 part of the table
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"},
      {"fork", "spoon", "knife", "soup plate", "side plate", "chair"}};

  std::cout << "\x1b[36mTableware before guests arrive\x1b[37m\n";
  printServe(serve);

  std::cout << "\x1b[36mThe guest came with a child\x1b[37m\n";
  serve[6].push_back("additional chair");
  printServe(serve);

  std::cout << "\x1b[36mThe spoon in the third place in the second part of the "
               "table disappeared\x1b[37m\n";
  serve[9].erase(serve[9].begin() + 1);
  printServe(serve);

  std::cout << "\x1b[36mThe VIP guest handed over his spoon\x1b[37m\n";
  serve[9].insert(serve[9].begin() + 1, serve[1][1]);
  serve[1].erase(serve[1].begin() + 1);
  printServe(serve);

  std::cout << "\x1b[36mThe waiter took the dessert spoon\x1b[37m\n";
  serve[1].pop_back();
  printServe(serve);

  std::cout << "\x1b[33mNo further incidents occurred.\n"
            << "The story is silent on whether the waiter brought a spoon to "
               "the VIP guest...\x1b[37m\n";

  return 0;
}