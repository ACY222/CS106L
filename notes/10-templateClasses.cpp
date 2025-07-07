/*  1. Template classes: it generalizes logic across types
 *  2. Const correctness
 *      - Const makes an entire object read-only
 *      - Mark methods const when they don't modify the object. Thus we can use it
 *      when the object is passed as const (Objects marked const can only make
 *      use of the const interface)
 *      - Const_cast and mutable can circumvent compiler in rare cases. But in
 *      most cases don't use them.
 */
#include <iostream>
#include "10-vector.h"

void printVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printVec(v);
    return 0;
}
