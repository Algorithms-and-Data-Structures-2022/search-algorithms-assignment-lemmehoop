#pragma once

#include "assignment/private/search_strategy.hpp"

namespace assignment {

  struct BinarySearchRecursive final : SearchStrategy {

    /**
     * Двоичный поиск элемента в массиве (рекурсия).
     *
     * Область поиска элемента каждый раз сокращается вдвое.
     * Примечание: гарантируется, что элементы входного массива находятся в порядке неубывания.
     *
     * Сложность ~ O(log N).
     * Сложность сортировки (в лучшем случае) ~ O(N * log N)
     *
     * @param data - массив элементов
     * @param search_element - значение элемента, которое необходимо найти
     * @return индекс найденного элемента
     */
    std::optional<int> Search(const std::vector<int>& data, int search_element) const override;

   private:
    /**
     * Вспомогательная функция для реализации рекурсивного поиска элемента в массиве.
     *
     * @param data - массив элементов
     * @param search_element - значение элемента, которое необходимо найти
     * @param left_index - индекс левой границы области поиска
     * @param right_index - индекс правой границы области поиска
     * @return индекс найденного элемента
     */
    std::optional<int> recursive_helper(const std::vector<int>& data, int search_element, int left_index,
                                        int right_index) const;
  };

}  // namespace assignment