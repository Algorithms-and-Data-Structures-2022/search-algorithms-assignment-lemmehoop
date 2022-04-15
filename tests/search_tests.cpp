#include <catch2/catch.hpp>

#include <algorithm>    // sort
#include <type_traits>  // is_same_v

#include "utils.hpp"  // rand_array

#include "assignment/linear_search_iterative.hpp"
#include "assignment/linear_search_recursive.hpp"
#include "assignment/linear_search_two_pointers.hpp"

#include "assignment/binary_search_iterative.hpp"
#include "assignment/binary_search_recursive.hpp"

#include "assignment/find_sum.hpp"

using namespace assignment;

constexpr int kMaxDataSize = 100;

std::unordered_set<int> all_sums(const std::vector<int>& data) {

  int sum = 0;
  std::unordered_set<int> res;

  for (int index = 0; index < static_cast<int>(data.size()) - 1; ++index) {
    for (int next = index + 1; next < data.size(); ++next) {
      sum = data[index] + data[next];

      if (res.count(sum) == 0) {
        res.insert(sum);
      }
    }
  }

  return res;
}

TEMPLATE_TEST_CASE("Search", "", LinearSearchIterative, LinearSearchRecursive, LinearSearchTwoPointers,
                   BinarySearchIterative, BinarySearchRecursive) {

  const int size = GENERATE(range(0, kMaxDataSize));
  auto data = utils::rand_array(size, -100, 100, true);

  // binary search requires that data is sorted
  if (std::is_same_v<TestType, BinarySearchIterative> || std::is_same_v<TestType, BinarySearchRecursive>) {
    std::sort(data.begin(), data.end());
  }

  // search strategy type
  const TestType search_strategy;

  if (size == 0) {

    SECTION("Search in empty data") {
      const int search_elem = GENERATE(range(-100, 101));

      CHECK_FALSE(search_strategy.Search(data, search_elem).has_value());
    }

  } else {

    SECTION("Search for an existing element") {
      const int elem_index = GENERATE_REF(range(0, size));
      const int search_elem = data[elem_index];

      CAPTURE(elem_index, search_elem, data);

      const auto search_result = search_strategy.Search(data, search_elem);

      REQUIRE(search_result.has_value());
      CHECK(search_result.value() == elem_index);
    }

    SECTION("Search for a non-existing element") {
      const int search_elem = GENERATE(range(-150, -100), range(101, 151));

      CHECK_FALSE(search_strategy.Search(data, search_elem).has_value());
    }
  }
}

TEST_CASE("TwoPointers::FindSum") {

  const int size = GENERATE(range(1, kMaxDataSize));

  auto data = utils::rand_array(size, -50, 100);
  std::sort(data.begin(), data.end());

  const auto check_set = all_sums(data);

  SECTION("find an existing sum") {

    for (int expected_sum : check_set) {

      const auto found = find_sum(data, expected_sum);

      CAPTURE(data, expected_sum);
      REQUIRE(found.has_value());

      const int sum = data[found->first] + data[found->second];
      CHECK(expected_sum == sum);
    }
  }
}
