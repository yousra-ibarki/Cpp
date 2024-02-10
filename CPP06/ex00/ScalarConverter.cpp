#include "ScalarConverter.hpp"

// double result = static_cast<double>(integerValue);

ScalarConverter::ScalarConverter()
{
    std::cout << "Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    if (this != &obj)
        *this = obj;
    return *this;
}

void ScalarConverter::convert(std::string str)
{
    (void)str;
    char cType;
    int iType;
    float fType = 0.00;
    double dType;

    // For displaying one single character
    if ((str.length() == 1 && str[0] >= 65 && str[0] <= 90) || (str[0] >= 97 && str[0] <= 122 && str.length() == 1))
    {
        std::cout << "char: " << str[0] << std::endl;
        // return;
    }

    // For displaying the infinity
    else if(str == "-inf" || str == "-inff")
    {
        dType = -std::numeric_limits<double>::infinity();
        std::cout << "double: " << dType << std::endl;
    }
    else if(str == "inf" || str == "inff")
    {
        dType = std::numeric_limits<double>::infinity();
        std::cout << "double: " << dType << std::endl;
    }
    //For displaying the nan and nanf
    else if(str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        fType = std::numeric_limits<double>::quiet_NaN();
        std::cout << "float: " << fType << "f" << std::endl;
        dType = std::numeric_limits<double>::quiet_NaN();
        std::cout << "double: " << dType << std::endl;
        return ;
    }


    iType = stoi(str);
    //For displaying the characters 
    if (iType > 32 && iType < 127)
    {
        cType = static_cast<char>(iType);
        std::cout << "char: '" << cType << "'" << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << iType << std::endl;

    fType = stof(str);
    std::cout << "float: " << fType << "f" << std::endl;

    dType = stod(str);
    std::cout << "double: " << dType << std::endl;
}