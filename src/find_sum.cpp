#include "assignment/find_sum.hpp"  // find_elements

namespace assignment {

  std::optional<std::pair<int, int>> find_sum(const std::vector<int>& data, int sum) {

    // Tips: для создания пары (pair) используйте функцию std::make_pair

    int left = 0;
    int right = data.size() - 1;

    if (right < 0) {
      return std::nullopt;
    }

    while (left <= right) {
      int new_sum = data[left] + data[right];
      if (new_sum == sum) {
        return std::make_pair(left, right);
      }
      if (new_sum < sum) {
        left += 1;
      }
      if (new_sum > sum) {
        right -= 1;
      }
    }
    return std::nullopt;
  }

}  // namespace assignment