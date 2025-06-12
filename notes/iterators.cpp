/*  Iterators: How do we traverse containers?
 *  1. Iterators: for (auto elem : container) {} doesn't work for some
 *      containers. So we introduce iterator.
 *      Containers and iterators work together to allow iteration.
 *      - There are many types of iterators: 
 *          input(istream), output(ostream), forward(unordered_map/set),
 *          bidirectional(map, set), random access(deque, vector)
 *      - Iterator iterface:
 *          auto it = c.begin();// an iter to the first element of container
 *          ++it;               // move iter forward
 *          if (it == c.end())  // an iter to one elem after the end of container
 *          *it                 // deference
 *  2. Pointer: A pointer points to any object, an iterator points to a
 *      container element. They have similar interfaces
 *      C++ pointer is similar to C pointer
 * */

#include <set>
#include <iostream>
#include <queue>

int main() {
    using namespace std;
    set<int> nums {1, 2, 3, 4, 5};
    queue<const int*> odds;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        if (*it % 2 == 1) {
            odds.push(it);
        }
    }
    while (!odds.empty()) {
        cout << *odds.front() << ' ';
        odds.pop();
    }
    return 0;
}
