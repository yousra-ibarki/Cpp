#include <iostream>
#include <vector>
#include <deque>

template <typename Container>
void iterateContainer(const Container& cont) {
    for (typename Container::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::deque<int> deq = {6, 7, 8, 9, 10};
    
    std::cout << "Iterating through vector:" << std::endl;
    iterateContainer(vec);
    
    std::cout << "Iterating through deque:" << std::endl;
    iterateContainer(deq);
    
    return 0;
}
