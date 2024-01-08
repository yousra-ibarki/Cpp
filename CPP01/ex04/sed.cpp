#include "sed.hpp"

int ft_count(std::string line, std::string str1){
    int count = 0;
    size_t pos = 0;
    while(((pos = line.find(str1, pos)) != std::string::npos)){
      count++;
      pos += str1.size();
    }
   //std::cout << count << std::endl;
    return count;
}

std::string ft_replace(std::string line, std::string str2, std::string str1){
    int pos;
    int count = ft_count(line, str1);
    for(int i = 0; i < count ; i++){
    pos = line.find(str1);
    line.insert(pos, str2);
    pos = line.find(str1);
    line.erase(pos, strlen(str1.c_str()));
    }
    return line;
}
