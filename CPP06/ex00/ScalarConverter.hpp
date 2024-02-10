#ifndef CAST_HPP
#define CAST_HPP


#include <iostream>
#include <string>
#include <limits>

class ScalarConverter{
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator=(const ScalarConverter& obj);
    static void convert(std::string str);
};

#endif