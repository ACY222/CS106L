#include <algorithm>
#include "15-photo.h"

photo::photo(int width, int height) :
    width(width),
    height(height),
    data(new int[width * height]) {}

photo::photo(const photo& other) : 
    width(other.width),
    height(other.height),
    data(new int[other.width*other.height]) 
{
    std::copy(other.data, other.data + width * height, data);
}

photo::photo(photo&& other) :
    width(other.width),
    height(other.height),
    data(other.data) 
{
    other.data = nullptr;
}

photo& photo::operator=(const photo& other) {
    if (this == &other) return *this;

    delete[] data;
    width = other.width;
    height = other.height;
    data = new int[other.width * other.height];
    std::copy(other.data, other.data + width * height, data);
    return *this;
}


photo& photo::operator=(photo&& other) {
    if (this == &other) return *this;

    width = other.width;
    height = other.height;
    data = other.data;
    other.data = nullptr;
    return *this;
}

photo::~photo() {
    delete[] data;
}
