#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform binary search and insert the value into the sorted vector
void binary_insert(std::vector<int>& vec, int value) {
    std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

int main() {
    // Initialize mainS and pend vectors
    std::vector<int> mainS;
    mainS.push_back(7);
    mainS.push_back(8);
    mainS.push_back(46);
    mainS.push_back(53);
    mainS.push_back(100);

    std::vector<int> pend;
    pend.push_back(11);
    pend.push_back(2);
    pend.push_back(27);

    // Insert each element from pend into mainS using binary search
    for (std::vector<int>::iterator it = pend.begin(); it != pend.end(); ++it) {
        binary_insert(mainS, *it);
    }

    // Print the sorted mainS vector
    for (std::vector<int>::iterator it = mainS.begin(); it != mainS.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
