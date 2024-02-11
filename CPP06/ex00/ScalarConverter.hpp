#ifndef CAST_HPP
#define CAST_HPP


#include <iostream>
#include <string>
#include <limits>

class ScalarConverter{
private:
    ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& obj);
    ScalarConverter(const ScalarConverter& obj);

public:
    ~ScalarConverter();
    static void convert(std::string str);
};

#endif