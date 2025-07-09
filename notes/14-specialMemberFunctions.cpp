/*  Special Member Functions
 *
 *  1. An overview:
 *      There are 6 special member functions(SMF), including:
 *          default constructor, copy constructor, copy assignment operator,
 *          destructor, move constructor, move assignment constructor
 *
 *      This is a widget example:
 *      class Widget {
 *      public:
 *          // Default constructor: takes no parameters and creates a new
 *          // object, is called every time a new instance of the class is
 *          // created  
 *          Widget();
 *          // Copy constructor: creates a new object as a member-wise copy of
 *          // another. Triggered when we 
 *              - initializing a new object: Widget b(a); Widget b = a;
 *              - parameter passed by value: func(a);
 *              - return:   return a;
 *          Widget (const Widget& w);
 *          // Copy assignment constructor: assigns an already existing object
 *          // to another(already existing object)
 *          Widget& operator = (const Widget& w);
 *          eg:
 *              Widget b;
 *              b = a;
 *          // Destructor: called when the object goes out of scope
 *          ~Widget();
 *          // the last two are not the focus of today
 *          Widget (Widget&& rhs);              // move constructor
 *          Widget& operator = (Widget&& rhs);  // move assignment constructor
 *      }
 *
 *      Copy Constructor vs Copy Assignment Operator:
 *      Copy Constructor:
 *          Widget widgetOne;
 *          Widget widgetTwo = widgetOne;       // copy when being initialized
 *      Copy Assignment Operator:
 *          Widget widgetOne;
 *          Widget widgetTwo;
 *          widgetTwo = widgetOne;              // copy after being initialized
 *      Another example:
 *          // const object can use Copy Constructor but not Copy Assignment ...
 *          // this is legel, const can be changed when being initialized
 *          const int i = 4;
 *          // this is illegal, const can't be changed after being initialized
 *          const int i;
 *          i = 4;
 *      
 *      We don't have to write out any of these! They all have default versions
 *      that are generated automatically. But if we're managing memory, we need
 *      to override.
 *
 *
 *  2. Copy and copy assignment
 *      Review our vector from Lec 8
 *          template <typename T>
 *          Vector<T>::Vector() {
 *              _size = 0;
 *              _capacity = 4;
 *              _data = new T[_capacity];
 *          }
 *      When we create a constructor, we need to initialize all of our member
 *      variables. However, initializing them to be the default value and then
 *      reassigning is inefficient! There are two steps happening here:
 *      1. _size, _capacity, and _data may have been default initialized
 *      2. assign special values to the variables, which doubles the work
 *
 *      We can use list initialization to declare and initialize them with desired
 *      values at once:
 *          template <typename T>
 *          Vector<T>::Vector() : _size(0), _capacity(4), _data(new
 *              T[_capacity]) {};
 *      It's quicker and more efficient to directly construct member variables
 *      with intended values, and can be used for any constructor, even
 *      non-default ones with parameter. If the variable is a non-assignable
 *      type, reference, for example, then it only works with initializer lists
 *
 *      By default, the copy constructor will create copies of each member
 *      variables, which is member-wise copying. If the variable is a pointer,
 *      a memberwise copy will point to the same allocated memory, not a fresh
 *      copy. This is problematic because anything done to one pointer affects
 *      the other
 *
 *      Many times, you will want to create a copy that does more than just
 *      copies the member variables. Deep copy: an object that is a complete,
 *      independent copy of the original. In these cases, you'd want to override
 *      the default special member functions with your own implementation.
 *      Declare them in the .h and write their implementation in the .cpp.
 *
 *  3. Delete
 *      With delete, we can selectively allow functionality of special member
 *      functions. This has lots of uses. 
 *      For example, you have a class that handles all your passwords, you want
 *      to prevent copies, then you can set the special member functions to
 *      delete to remove their functionality:
 *      constructors:
 *          class PasswordManager {
 *          public:
 *              PasswordManager();
 *              // other methods...
 *              // remove copy constructor
 *              PasswordManager(const PasswordManager& rhs) = delete;
 *              // remove copy assignment operator
 *              PasswordManager& operator = (const PasswordManager& rhs) = delete;
 *          }
 *
 *  
 *  4. Philosophy time
 *      Rule of Zero: If the default SMFs work, don't define your own. We should
 *      only define new ones when the default ones generated by the compiler
 *      won't work. This usually happens when we work with dynamically allocated
 *      memory, like pointers to things on the heap.
 *
 *      Rule of Three: If you need a custom destructor, then you also probably
 *      need to define a copy constructor and a copy assignment operator for
 *      your class.
 */
#include <vector>
using namespace std;
vector<int> func(vector<int> vec0) {    // copy constructor(the parameter)
    vector<int> vec1;           // default constructor
    vector<int> vec2(3);        // custom constructor, not SMF
    vector<int> vec3{3};        // uniform initialization, not SMF
    vector<int> vec4();         // function declaration
    vector<int> vec5(vec2);     // copy constructor
    vector<int> vec6{};         // empty vector via list initialization
    vector<int> vec7{static_cast<int>(vec2.size() + vec6.size())};  // list init
    vector<int> vec8 = vec2;    // copy constructor
    vec8 = vec2;                // copy assignment operator
    return vec8;                // copy constructor
    // list init is in implementation layer, uniform init is in syntax layer
    // So list initialization is also uniform initialization
}
