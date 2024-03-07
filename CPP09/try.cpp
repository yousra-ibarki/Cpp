#include <iostream>
#include <string>

int main() {
    std::string text = "2011-01-03    |     3";
    std::string result;

    bool spaceFound = false;
    for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
        if (*it == ' ') {
            if (!spaceFound) {
                result += *it; // Add the first space
                spaceFound = true;
            }
        } else {
            result += *it;
            spaceFound = false;
        }
    }

    std::cout << "Original string: " << text << std::endl;
    std::cout << "String with single spaces: " << result << std::endl;

    return 0;
}
