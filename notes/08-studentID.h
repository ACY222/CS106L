class StudentID {
private:    // data member declarations
    // we can define functions in this part, other program can't use it, but
    // public function can
    std::string name;
    std::string id;
    int age;
public:     // member function prototypes
    // constructor for our StudentID, the syntax is just the name of the class
    StudentID(std::string name, std::string id, int age);
    // default constructor. Overloading!
    StudentID();
    // methods to get name and id repectively
    std::string getName();
    std::string getID();
    int getAge();
    void setName(std::string name);
    void setID(std::string id);
    void setAge(int age);
    void printInformation();
    ~StudentID();
};
