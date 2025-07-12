#include <iostream>
#include <fstream>
#include <memory>
#include <string>
// #include <memory>

using namespace std;

class Pet {
private:
  string firstName;
  string lastName;
  string type;
  int petId;
public:
  Pet();
  Pet(int id): petId(id) {};
  string getType() {
    return type;
  }
  string getFirstName() {
    return firstName;
  }
  string getLastName() {
    return lastName;
  }
};
/*  1. RAII: Resource Acquisition Is Initialization
 *    Other names:
 *      - SBRM: Scope Based Memory Management
 *      - CADRE: Constructor Acquires, Destructor Releases
 *    It means:
 *      - All resources used by a class should be acquired in the constructor
 *      - All resources used by a class should be released in the destructor
 *    By doing so:
 *      - We avoid half-valid states
 *      - No matter what, the destructor is called whenever the resource goes
 *      out of scope, so no memory leaks will happen
 *      - One more thing: the resource is usable immediately after it's created
*/

// Here are some examples
/*  How many code paths in this function? At least 23!
 *   (1): copy constructor of function parameter
 *   (5): constructor of temp strings
 *   (6): call to type, getFirstName * 3, getLastName * 2
 *   (10): user overloaded operators
 *   (1): copy constructor of returned string
 *  So what if throw exception between `new` and `delete`? Memory Leak!
 */
string returnNameCheckPawsome(int petId) {
  Pet* p = new Pet(petId);
  if (p->getType() == "Dog" || p->getFirstName() == "Fluffy") {
    cout << p->getFirstName() << " " << p->getLastName()
      << " is paw-some!\n";
  }
  delete p;
  return p->getFirstName() + " " + p->getLastName();
}

/*  This is not unique to just pointers!
 *    Heap memory: new | delete
 *    Files: open | close
 *    Locks: try_lock | unlock
 *
 *  How to ensure that we properly release resources in the case that we have
 *  an exception? RAII!
 *
 *  We acquire resources in constructor and release resources in destructor so
 *  that no matter what happens, as long as the object leave the scope, the
 *  resources are released automatically!
*/

// the ifstream is opened and closed in code, not constructor and destructor
// RAII doesn't like this
void badPrintFile(string filePath) {
  ifstream input;
  input.open(filePath);
  // print the file
  input.close();
  return;
}

// This is what we want!
void printFile(string filePath) {
  ifstream input(filePath);
  // do whatever you like
  //
  // no explicit close is needed, it's handled by destructor
  // the close() & open() are just for compability
  return;
}

// But how to solve this issue?
void badRawPtrFn() {
  Pet* p = new Pet;
  // do some stuff with p
  // if exception thrown, p never deleted
  delete p;
}

/*  The thought to solve previous problems is to wrap it in an object to ensure
 *  that the resource is acquired in constructor and released in destructor
 *
 *  Now we can do the same. It's RAII for memory
 *  And the "wrapper" pointers are called "smart pointers"
 *
 *  2. Smart Pointers: there're three types of smart pointers
 *    - std::unique_ptr: Uniquely owns its resource, can't be copied
 *    - std::shared_ptr: Can make copies, destructed when the underlying
 *    memory goes out of scope
 *    - std::weak_ptr: similar to shared_ptr, but doesn't contribute to the
 *    reference count. Used to deal with circular references of shared_ptr.
 *
 *  But why we cannot copy unique_ptr? Here is an example:
 *    considering we have a unique_ptr x, and we copy it using y, When one of
 *    them, let's say, x, goes out of scope, destructor is called and the resource
 *    is released. Now y points to an unallocated memory. When y goes out of
 *    scope, the memory is deleted twice.
 *
 *  We can assign the copy constructor and copy assign operator to be delete to
 *  realize this.
*
*   But this is not convenient, what should we do if we really want to copy?
*     std::shared_ptr gets around our issue of tring to copy:
*       Resource can be stored by any number of shared_ptr
*       Deleted when none of them point to it
*     How are these implemented? Reference counting!
*       The idea is: store an int that keeps track of the number currently
*       referencing that data
*         Gets incremented in copy constructor/copy assignment operator
*         Gets decremented in destructor or when overwritten with copy
*         assignment
*       Free the resourece when reference count hits 0
*/
void betterRawPtrFn() {
  std::unique_ptr<Pet> p(new Pet);
  // or we can use shared_ptr
  // std::shared_ptr<Pet> p(new Pet);
  // do some stuff with p
}
// However, we are still using new explicitly, we don't like it
// So let's do it in this way
// Always using std::make_unique<t>() and std::make_shared<T>()
void finalRawPtrFn() {
  std::unique_ptr<Pet> p = std::make_unique<Pet>();
  // or use shared_ptr
  std::shared_ptr<Pet> anotherP = std::make_shared<Pet>();
  // do some stuff with them
}
