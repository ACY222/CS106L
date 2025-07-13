class photo {
public:
  photo(int width, int height);             // constructor
  photo(const photo& other);                // copy constructor
  photo& operator=(const photo& other);     // copy assignment operator
  ~photo();                                 // destructor
  // now we have two more SMFs
  // if the other is rvalue, we use move instead
  photo(photo&& other);                     // move constructor
  photo& operator=(photo&& other);          // move assignment operator
private:
  int width;
  int height;
  int* data;
};
