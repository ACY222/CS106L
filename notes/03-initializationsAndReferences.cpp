/* 1. Use uniform initialization, which is ubiquitous and safe: it works for
 *      all types and objects, and it dosen't allow for narrowing conversions.
 *      And use structured binding, which is quite neat.
 * 2. References(&) are a way to alias variables. It take in the actual piece of
 *      memory rather than making a copy, which is more efficient. And you can
 *      modify it directly, like a pointer. You can only reference a lvalue.
 * 3. Const is a way to ensure that you cannot modify the variable, and a way to
 *      announce that you won't modify the variable.
 *
 *      You cannot declare a non-const reference to a const variable. But you
 *      can declare a const reference to a non-const variable.
 *
 *      If a function is const, we call it const member function, and it won't
 *      modify the state of object on which it is called.
 * */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using pairVector = vector<pair<int, int>>;

// With these two '&' we can really shift the number in nums
void shift(pairVector &nums) {
  for (auto& [num1, num2] : nums) {
    num1++;
    num2++;
  }
}
// Or we can do it like this:
void anotherShift(pairVector &nums) {
  for (size_t i = 0; i < nums.size(); i++) {
    nums[i].first++;
    nums[i].second++;
  }
}

int main() {
  pairVector nums {{1, 3}, {2, 4}, {3, 5}};   // uniform initialization
  anotherShift(nums);
  for (auto [num1, num2] : nums) {
    cout << num1 << ", " << num2 << endl;
  }
  return 0;
}
