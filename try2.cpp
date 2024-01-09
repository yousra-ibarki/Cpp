#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    // Overloading the << operator
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << "MyClass(" << obj.value << ")";
        return os;
    }
};

int main() {
    MyClass myObject(42);

    // Using the overloaded << operator to print the object
    std::cout << "Object: " << myObject << std::endl;

    return 0;
}
