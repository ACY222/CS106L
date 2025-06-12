/* 1. A struct bundles named variables into a new type 
 * 2. To use std::pair, you must `#include <utility>` even though some
 *      compilers help you with it. Otherwise it may fail in other mathcine
 * 3. We can create type aliases with the using keyword. It's kinda like
 *      a variable for types
 * 4. The auto keyword tells the compiler to infer the type
 * 5. Function overload: treat different parameters in different ways
 * */
#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;
using Points = pair<double, double>;
using Solutions = pair<bool, Points>;

// overload
double func(double x) {
    return 3 * x;
}
double func(int x) {
    return 3.0 + x;
}

Solutions solveQuadratic(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        return {false, {0.0, 0.0}};
    }
    else {
        double sol1, sol2;
        delta = sqrt(delta);
        sol1 = (-b + delta) / (2 * a);
        sol2 = (-b - delta) / (2 * a);
        return {true, {sol1, sol2}};
    }
}

int main() {
    // Three ways to initialize objects
    // 1. Direct inistialization, it relies on the use of '=' or '()'. And it
    //  doesn't produce an error
    int foo = 12.0;
    int bar(12.0);
    // 2. Uniform initialization, a consistent, type-safe syntax that uses '{}'
    //  to initialize objects
    vector<int> vec {1, 2, 3, 4};
    // 3. Structured binding, a method of initializing variables from data
    //  structures with size known at compile time
    auto [res, points] = solveQuadratic(1, -3, 2);

    int x = 5;
    int& reference = x;
    reference = 10;   // now x = 10
    cout << func(3.0) << endl << func(3) << endl;
    auto result = solveQuadratic(1, -3, 2);
    if (result.first) {
        cout << "Solutions: " << result.second.first << ", " <<
            result.second.second << endl;
    }
    else {
        cout << "No solutions" << endl;
    }
    return 0;
}
