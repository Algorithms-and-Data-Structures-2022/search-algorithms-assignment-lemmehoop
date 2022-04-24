#include "assignment/linear_search_iterative.hpp"

namespace assignment {

  std::optional<int> LinearSearchIterative::Search(const std::vector<int>& data, int search_element) const {

    for (int i = 0; i < data.size(); i++) {
      if (data[i] == search_element) {
        return i;
      }
    }

    return std::nullopt;
  }

}  // namespace assignment