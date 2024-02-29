#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> data;
    size_t start = 0, end = 0;
    while ((end = str.find(delimiter, start)) != std::string::npos) {
        data.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    data.push_back(str.substr(start));
    return data;
}

int main() {
    std::string line = "This,is,a,sample,line,to,split";
    std::vector<std::string> data = split(line, ',');

    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;
    }

    return 0;
}
