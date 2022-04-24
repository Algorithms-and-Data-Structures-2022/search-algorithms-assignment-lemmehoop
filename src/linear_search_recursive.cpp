#include "assignment/linear_search_recursive.hpp"

namespace assignment {

  std::optional<int> LinearSearchRecursive::Search(const std::vector<int>& data, int search_element) const {
    // запускаем рекурсивный метод с индексом последнего элемента массива
    return recursive_helper(data, search_element, static_cast<int>(data.size() - 1));
  }

  std::optional<int> LinearSearchRecursive::recursive_helper(const std::vector<int>& data, int search_element,
                                                             int curr_index) const {
    // Tips:
    // 1. Укажите случаи выхода из рекурсии: (а) обошли все элементы и (б) элемент найден.
    // 2. Вызовите рекурсивный метод с другим индексом.
    if (curr_index < 0) {
      return std::nullopt;
    }

    if (data[curr_index] == search_element) {
      return curr_index;
    }

    return recursive_helper(data, search_element, curr_index - 1);
  }

}  // namespace assignment