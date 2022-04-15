#pragma once

#include "assignment/private/search_strategy.hpp"

namespace assignment {

  struct LinearSearchIterative final : SearchStrategy {

    /**
     * Последовательный поиск элемента в массиве.
     *
     * Сложность ~ O(N).
     *
     * @param data - массив элементов
     * @param search_element - значение элемента, которое необходимо найти
     * @return индекс найденного элемента
     */
    std::optional<int> Search(const std::vector<int>& data, int search_element) const override;
  };

}  // namespace assignment