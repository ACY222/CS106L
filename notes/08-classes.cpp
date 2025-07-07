/*  1.Classes containing 
 *    - a sequence of objects of various types
 *    - a set of functions for manipulating these objects
 *    - a set of restrictions on the access of these objects and function;
 *  
 *  Structures are classes without access restrictions.(Have functions?)
 *
 *  2. Header File (.h) vs Source Files (.cpp)
 *    - Header file:
 *      - defines the interface
 *      - contains: function prototypes, class declarations, type
 *      definitions, macros, constants
 *      - is shared across source files
 *      - example: void someFunction();
 *    - Soucrce file:
 *      - implements class functions
 *      - contains: function implementations, executable code
 *      - is compiled into an object file
 *      - example: void someFunction() {...};
 *  3. Class design:
 *    - A constructor, which initializes the state of newly created objects
 *    - Private member functions/variables
 *    - Public member functions (interface for a user)
 *    - Destructor
 *  4. Inheritance: Allow us to design powerful and versatile abstractions that
 *    can help us model complex relationships in code
 */
#include <string>
#include "08-studentID.h"
#include <iostream>

// default constructor
StudentID::StudentID() {
    name = "Ai Chang";
    id = "PB22111620";
    age = 21;
}

// The first StudentID is namespace, like std. In our .cpp file we need to use
// our class as the namespace when defining member functions
StudentID::StudentID(std::string name, std::string id, int age) {
    this->name = name;
    this->id = id;
    this->age = age;
}

// list initialization constructor
/* StudentID::StudentID(std::string name, std::string id, int age): */
/*     // The last {} is the function body(empty), I don't like it. */
/*     // But it's said to be more efficient, so try to use it if necessary */
/*     name{name}, id{id}, age{age} {}; */      

std::string StudentID::getName() {
    return name;
}

std::string StudentID::getID() {
    return id;
}

int StudentID::getAge() {
    return age;
}

void StudentID::setName(std::string name) {
    this->name = name;
}

void StudentID::setID(std::string id) {
    this->id = id;
}

void StudentID::setAge(int age) {
    if (age > 0) {
        this->age = age;
    }
}

void StudentID::printInformation() {
    std::cout << "Student name: " << name << '\n'
        << "Student id: " << id << '\n'
        << "Student age: " << age << '\n';
}

// The destructor is not explicitly called, it's automatically called when an
// object goes out of scope
StudentID::~StudentID() {
    // In this class we don't allocate space explicitly, so nothing to do
    // free/deallocate any data here
    std::cout << "Bye~ Student.\n";
}

int main() {
    StudentID ac;
    StudentID dd { "Dingyi", "222", 21 };
    ac.StudentID::printInformation();
    dd.StudentID::printInformation();
    // std::cout << ac.getName() << '\n' << ac.getAge() << '\n';
    return 0;
}
