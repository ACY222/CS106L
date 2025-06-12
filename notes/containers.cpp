/*  Containers: How do we store groups of things?
 *  1. Every C++ container is a template
 *  2. Sequence containers store a linear sequence of elements
 *      - vector: push_back, pop_back, size, clear, empty, etc.
 *      - deque: A deque("deck") is a double-ended queue, which
 *          allows efficient insertion and removal at either end.
 *          It has the same interface as vector, except we can
 *          push_front/pop_front
 *  3. Associate containers organize elements by unique keys
 *      - map: map<K, V> stores a collections of pair<const K, V>. It requires
 *          K to have an iterator <(less) (be able to be compared)
 *          insert, count, contains, erase, empty, etc.
 *      - unordered_map<K, V>: An optimized version of map, much faster, 
 *          implemented by hash function. So it requires K to be hashable.
 *      - set: set stores a collection of unique items. It's a map without 
 *          values. Both of them are implemented by red-black tree
 *      - unordered_set: An unordered_map without values
 *      - Above all, unordered containers are more efficient, according to
 *          hasing and small load factor
 * */

#include <vector>
#include <iostream>

using namespace std;
void vectorExample() {
    /* vector<type> v(n);       create a vector with n copies of 0
     * vector<type> v(n, k);    create a vector with n copies of k
     * */
    vector<int> vec {1, 2, 3, 4};
    vec.pop_back();     // pop the last element, return nothing
    vec.push_back(5);   // push 5 in the end of vec
    vec.push_back(6);

    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << ", "; // 1, 2, 3, 5, 6,
    }
    cout << endl;

    // another way to do that
    for (auto elem : vec) {     // applies for all iterable containers
        cout << elem << ", ";
    }
    cout << endl;

    // save making a potential expensive copy of each element, and make sure
    //  that elements in vec won't be changed
    for (const auto& elem : vec) {
        cout << elem << ", ";
    }
    cout << endl;

    vec.clear();        // clear the vector
    if (vec.empty()) {  // check is vec is empty
        cout << "Nothing is in the vector" << '\n';
    }
}

int main() {
    vectorExample();
    return 0;
}
