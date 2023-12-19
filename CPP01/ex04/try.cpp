#include <iostream>
#include <string>

int main() {
    std::string mainString = "Hello, World!";
    std::string searchString = "World";

    // Search for the substring
    size_t found = mainString.find(searchString);

    if (found != std::string::npos) {
        std::cout << "Substring found at position " << found << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}
