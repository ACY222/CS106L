/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <ostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  friend std::ostream& operator<<(std::ostream &out, const User &user);
  // 1. Implement a destructor for the `User` class. To do so, 
  // implement the `~User()` SMF.
  // 2. Make the `User` class copy constructible. To do so, 
  // implement the `User(const User& user)` SMF.
  // 3. Make the `User` class copy assignable. To do so, 
  // implement the `User& operator=(const User& user)` SMF.
  // 4. Prevent the `User` class from being move constructed. To 
  // do so, delete the `User(User&& user)` SMF. 
  // 5. Prevent the `User` class from being move assigned. To 
  // do so, delete the `User& operator=(User&& user)` SMF.
  ~User();
  User(const User& user);
  User& operator=(const User& user);
  User(User&& user) = delete;
  User& operator=(User&& user) = delete;

  User& operator+=(User& rhs);
  bool operator<(const User& rhs) const;
  


private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};
