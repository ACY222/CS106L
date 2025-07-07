/*  1. Operator Overloading: Recall that a std::map<K, V> requires K to have an
 *  operator <. But why should we use operators at all?
 *  
 *  The motivation is operators allow you to convey meaning about types that
 *  functions don't.
 *
 *  How do operators work with classes?
 *      - Just like we declare functions in a class, we can declare an operator's
 *      functionality.
 *      - When we use the operator with our new object, it performs a custom
 *      function or operation
 *      - Just like in function overloading, if we give it the same name, it
 *      will override the operator's behavior
 *
 *  Operators that can't be overloaded: 
 *      - scope resolution: '::'
 *      - ternary: '?'
 *      - member access: '.'
 *      - pointer-to-member access: '.*'
 *      - object size, type, and casting: 'sizeof()', 'typeid()', 'cast()'
 *  Other operators can be overloaded
 *
 *  Two ways to overloaded:
 *      - Member overloading: Declares the overloaded operator within the scope
 *      of you class. The lhs must be the class, so it's less flexible
 *      - Non-member overloading: Declare the overloaded operator outside of
 *      class definitions, define both the left and right hand objects as
 *      parameters
 *  The second one is actually preffered by the STL, and is more idiomatic C++
 *      - Allows for the lhs to be a non-class type
 *      - Allows us to oveload operators with classes we don't own
 *  Eg:
 *      bool StanfordID::operator< (const StanfordID& rhs) const {...} {
 *          // we can repalce lhs with this->id, and replace id with getId()
 *          return id < rhs.id;
 *          // or 
 *          return id < rhs.getId();
 *      }
 *
 *      bool operator< (const StanfordID& lhs, const StanfordID& rhs) {
 *          return lhs.getId < rhs.getId;
 *          return lhs.id < rhs.id; // this is wrong: non-member overloading
 *                                  // can't access private variables
 *      }
 *
 *  With member operator overloading we have access to this-> and the variables
 *  of the class. But we can't access these with non-member overloading, because
 *  the operator is acting on two classes. So if there is no functions like
 *  getId(), we must use friend
 *
 *  But the friend keyword allows non-member functions or classes to access
 *  private information in another class. In the header of the target class you
 *  declare the operator overload function as a friend:
 *      friend bool operator < (const StanfordID& lhs, const StanfordID& rhs) {
 *          return lhs.id < rhs.id;
 *      }
 *
 *  Rules and Philosophies
 *      - Because operators are intended to convey meaning about type, the
 *      meaning should be obvious
 *      - The operators that we can define are oftentimes arithmetic operators,
 *      the functionality should be reasonably similar to their corresponding
 *      operations.
 *      - If the meaning is not obvious, then maybe define a function for this
 *
 *  There are some good practices like the rule of contrariety:
 *      bool StanfordID::operator == (const StanfordID& other) const {
 *          return (name == other.name) && (id == other.id);
 *      }
 *      bool StanfordID::operator != (const StanfordID& other) const {
 *          return !(*this == other);
 *      }
 *
 *  Final thoughts:
 *      - Operator overloading unlocks a new layer of functionality and meaning
 *      within objects that we define
 *      - Operators should make sense, the entire point is to convey some
 *      meaning about the type itself that functions don't.
 *      - Overload when you need to, for example if you're not using a stream
 *      with your type, then don't overload << or >>
 */
