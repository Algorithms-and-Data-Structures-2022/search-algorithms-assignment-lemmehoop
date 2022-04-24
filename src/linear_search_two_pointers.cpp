#include "assignment/linear_search_two_pointers.hpp"

namespace assignment {

  std::optional<int> LinearSearchTwoPointers::Search(const std::vector<int>& data, int search_element) const {

    int left_index = 0;
    int right_index = data.size() - 1;

    if (right_index < 0) {
      return std::nullopt;
    }

    while (left_index <= right_index) {
      if (data[left_index] == search_element) {
        return left_index;
      }
      if (data[right_index] == search_element) {
        return right_index;
      }
      left_index += 1;
      right_index -= 1;
    }

    return std::nullopt;
  }

}  // namespace assignment