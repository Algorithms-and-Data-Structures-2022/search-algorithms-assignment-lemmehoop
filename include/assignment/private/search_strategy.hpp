#pragma once

#include <vector>
#include <optional>

namespace assignment {

  /**
   * Интерфейс стратегии поиска элементов в массиве.
   */
  struct SearchStrategy {

    virtual ~SearchStrategy() = default;

    /**
     * Поиск элемента в массиве.
     *
     * Поведение зависит от конкретной реализации.
     *
     * @param data - массив элементов
     * @param search_element - значение элемента, которое необходимо найти
     * @return индекс найденного элемента
     */
    virtual std::optional<int> Search(const std::vector<int>& data, int search_element) const = 0;
  };

}  // namespace assignment