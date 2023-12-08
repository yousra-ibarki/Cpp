#include <iostream>
#include <string>

int main() {
    std::string str(10, ' '); // Create a string of size 10 with spaces
    
    std::cout << "Size of the string: " << str.size() << std::endl;
    std::cout << "String contents: " << str << std::endl;
    
    return 0;
}