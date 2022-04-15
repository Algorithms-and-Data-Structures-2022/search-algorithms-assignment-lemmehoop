#pragma once

#include "assignment/private/search_strategy.hpp"

namespace assignment {

  struct BinarySearchIterative final : SearchStrategy {

    /**
     * Двоичный поиск элемента в массиве.
     *
     * Область поиска элемента каждый раз сокращается вдвое.
     * Примечание: гарантируется, что элементы входного массива находятся в порядке неубывания.
     *
     * Сложность ~ O(log N).
     * Сложность сортировки (в лучшем случае) ~ O(N * log N).
     *
     * @param data - массив элементов
     * @param search_element - значение элемента, которое необходимо найти
     * @return индекс найденного элемента
     */
    std::optional<int> Search(const std::vector<int>& data, int search_element) const override;
  };

}  // namespace assignment