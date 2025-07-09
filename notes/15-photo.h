class photo {
public:
    photo(int width, int height);
    photo(const photo& other);
    photo& operator=(const photo& other);
    ~photo();
    // now we have two more SMFs
    photo(photo&& other);
    photo& operator=(photo&& other);
private:
    int width;
    int height;
    int* data;
};
