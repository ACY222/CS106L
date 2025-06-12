/*  1. Template functions: Templates automate code generation. So with it we can
 *  avoid code redundancy
 *  2. Template instantiation: use explicit instantiation if necessary
 *  3. Concepts: Templates are great, but the errors they produce when used 
 *  incorrectly are unintuitive. So we should put some constraints on templates.
 *  Using concepts can bring us better compiler error messages and better IDE
 *  support. But comcepts are still a new feature, STL doesn't support them
 *  fully yet.
 *  4. Variadic templates
 *
 *
 */
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
T min_basic(const T a, const T b) { 
    return a < b ? a : b;
}

template <typename T>
T min_ref(const T& a, const T& b) { // use references to avoid making a copy
    return a < b ? a : b;
}

// or we can make our template a little bit more flexible
template <typename T, typename U>
auto min_flex(const T& a, const U& b) {
    return a < b ? a : b;
}

template <typename Iterator, typename TElem>
Iterator find(Iterator begin, Iterator end, TElem value) {
    for (auto it = begin; it != end; ++it) {
        if (*it == value) {
            return it;
        }
    }
    return end;
}

template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
}

/* Here's how we can use the Comparable concept.
 * Another way to write this is:
 *
 * template <typename T> requires Comparable<T>
 *
 */
template <Comparable T>
T min_constrained(const T&a, const T& b) {
    return a < b ? a : b;
}

// base case function: needed to stop recursion
template <Comparable T>
T min(const T& v) { return v; }


template <Comparable T, Comparable... Args>
T min(const T& v, const Args&... args) {
    auto m = min(args...);
    return v < m ? v : m;
}



int main() {
    using std::cout; using std::endl;
    std::string firstName {"Ai"}, lastName {"Chang"};
    // explicit instantiation
    cout << min_basic<int>(3, 5) << ", " << min_basic<double>(3.2, 1.8) << '\n';
    // implicit instantiation, kinda like auto, let the compiler infer the types
    // for us
    cout << min_basic(3, 5) << ", " << min_basic(3.2, 1.8) << '\n';
    // it is ridiculous to compare between two char*
    // so we should use explicit instantiation in ambiguous cases like this
    cout << min_basic<std::string>("Ai", "Chang") << '\n';
    // this doesn't work
    /* cout << min(3, 3.14) << '\n'; */
    cout << min_basic<double>(3, 3.14) << '\n';       // it works
    cout << min_flex(3, 3.14) << '\n';
    return 0;
}
