/**
 * @file vector_user.h
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Функции вектора для решения задач после уроков.
 * @version 0.1
 * @date 19-01-2021
 * @copyright Copyright (c) 2021
 */

#ifndef INC_16_3_1_CLASSWORK__VECTOR_USER_H_
#define INC_16_3_1_CLASSWORK__VECTOR_USER_H_

#include <vector>

/**
 * @brief Добавление в конец вектора нового значения.
 * @note По идее можно обойтись resize(). Если не использовать push_back().
 * @param vecIn вектор, который надо увеличить.
 * @param val значение для вектора.
 * @return std::vector<int> новый вектор с измененным значением.
 */
void add(std::vector<int> &vecIn, const int &val);

/**
 * @brief Добавление в вектор нового значения в указанную позицию.
 * @param vecIn вектор, который надо изменить.
 * @param val значение для вектора.
 * @param pos позиция в очереди.
 * @return std::vector<int> новый вектор с измененным значением.
 */
std::vector<int> add(const std::vector<int> &vecIn, const int &val,
                     const int &pos);

/**
 * @brief Удаление последнего значения в векторе.
 * @param vec вектор, в котором нужно удалить.
 * @return std::vector<int> измененный вектор.
 */
void remove_index(std::vector<int> &vec);

/**
 * @brief 
 * @param vec вектор, в котором нужно удалить.
 * @param pos позиция в котором надо удалить
 * @return std::vector<int> вектор после удаления
 */
std::vector<int> remove_index(std::vector<int> &vec, const int &pos);

#endif  // INC_16_3_1_CLASSWORK__VECTOR_USER_H_
