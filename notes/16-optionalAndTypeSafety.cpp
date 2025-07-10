/* 1. Type Safety: the extent to which a language prevents typing errors, 
 *  a language guarantees the behavior of programs, a function signature
 *  guarantees the behavior of a function
 *
 * 2. See the following functions, 
 *  - What if vec is an empty vector? Undefined behavior! Function could
 *  crash, could give us garbage, could accidentally give us some actual
 *  value. After all, we can make no guarantees about what it does.
 *  - One solution is, check if it's empty before other actions. It's the
 *  programmers' job to enforce the precondition that vec be non-empty
 *
 * 3. std::optional<T>: it's a template class which will either contain a value
 *  of type T or contain nothing(expressed as nullopt, which is not nullptr)
 *
 * 4. std::optional methods:(I don't understand them, honestly)
 *  - .value(): returns the contained value or throws bad_optional_access error
 *  - .value_or(valueType val): returns the contained value or default value,
 *  parameter val
 *  - .has_value(): returns true if contained value exists, false otherwise
 *  - .and_then(function f): takes a null-optional instance of type T, 
 *  returns the result of calling f(value) (std::optional<U>) if 
 *  contained value exists, otherwise nullopt(f must return optional)
 *  - .transform(function f): returns the result of calling f(value) if 
 *  contained value exists, otherwise nullopt(f must return 
 *  optional<valueType>)
 *  - .or_else()(function f): returns value if it exists, otherwise returns 
 *  result of calling f
 *
 *
 * */

#include <vector>
#include <utility>
#include <optional>

using namespace std;
void removeOddsFromEnd0(vector<int>& vec) {
    while (vec.back() % 2 == 1) {
        vec.pop_back();
    }
}

// this works, but it's pretty unwieldy
void removeOddsFromEnd1(vector<int>& vec) {
    while (!vec.empty() && vec.back() % 2 == 1) {
        vec.pop_back();
    }
}

/*
// how can vec.back() have deterministic behavior in either case
template <typename valueType>
valueType& vector<valueType>::back() {
    return *(begin() + size() - 1);
}

// we can throw an error if it's empty
template <typename valueType>
valueType& vector<valueType>::back() {
    if(empty()) throw std::out_of_range;
    return *(begin() + size() - 1);
}

// we can return a pair, and using the first element to show if it's empty
// however, valueType may not have a default constructor
// even if it does, calling constructors is expensive
template <typename valueType>
pair<bool, valueType&> vector<valueType>::back() {
    if (empty()) {
        // using default constructor to return a default value
        return {false, valueType()};
    }
    return {true, *(begin() + size() - 1)};
}
*/

void removeOddsFromEnd2(vector<int>& vec) {
    auto isOdd = [](optional<int> num) {
        if (num) {
            return num % 2 == 1;
        }
        else {
            return nullopt;
        }
        // or we can do like this
        // return num ? (num % 2 == 1) : {};
    };
    while (vec.back().and_then(isOdd)) {
        vec.pop_back();
    }
}
