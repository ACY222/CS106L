#include <algorithm>
#include "15-photo.h"

// constructor
photo::photo(int width, int height) :
  width(width),
  height(height),
  data(new int[width * height]) {}

// copy constructor
photo::photo(const photo& other) :
  width(other.width),
  height(other.height),
  data(new int[other.width*other.height])
{
  std::copy(other.data, other.data + width * height, data);
}

// move constructor
photo::photo(photo&& other) :
  width(other.width),
  height(other.height),
  data(other.data)
{
  other.data = nullptr;
}

// copy assignment constructor
photo& photo::operator=(const photo& other) {
  if (this == &other) return *this;
  delete[] data;
  width = other.width;
  height = other.height;
  data = new int[other.width * other.height];
  std::copy(other.data, other.data + width * height, data);
  return *this;
}

// move assignment operator
photo& photo::operator=(photo&& other) {
  if (this == &other) return *this;

  width = other.width;
  height = other.height;
  data = other.data;
  other.data = nullptr;
  return *this;
}

// destructor
photo::~photo() {
  delete[] data;
}
