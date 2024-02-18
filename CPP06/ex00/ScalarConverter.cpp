#include "ScalarConverter.hpp"

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
    (void)obj;
    return *this;
}

void ScalarConverter::convert(std::string str)
{
    std::string cType = "";
    int iType = 0;
    float fType = 0.0;
    double dType = 0.0;
    int flag = 0;
    int count = 0;

    for (unsigned long i = 0; i < str.size(); i++)
    {
        if ((str.length() > 1 && str[i] > 0 && str[i] < 48 && str[i] && str[i] != '.' && str[i] != 45) || (str.length() > 1 && str[i] > 57 && str[i] < 127 && str[i] != 'f'))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;

            return;
        }
        else if (str[i] == '.')
        {
            flag = i;
            count++;
        }
    }
    for (unsigned long j = flag + 1; j < str.size(); j++)
    {
        if (str[j] == '0')
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        };
    }

    if ((str.length() == 1 && str[0] >= 65 && str[0] <= 90) || (str[0] >= 97 && str[0] <= 122 && str.length() == 1))
    {
        std::cout << "char: " << str[0] << std::endl;
        iType = static_cast<int>(str[0]);
        std::cout << "int: " << iType << std::endl;
        fType = static_cast<float>(str[0]);
        std::cout << "float: " << fType << ".0f" << std::endl;
        dType = static_cast<double>(str[0]);
        std::cout << "double: " << dType << ".0" << std::endl;

        return;
    }

    iType = std::atoi(str.c_str());

    if (str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        fType = -std::numeric_limits<float>::infinity();
        std::cout << "float: " << fType << "f" << std::endl;
        dType = -std::numeric_limits<double>::infinity();
        std::cout << "double: " << dType << std::endl;
        return;
    }
    else if (str == "inf" || str == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        fType = std::numeric_limits<float>::infinity();
        std::cout << "float: " << fType << "f" << std::endl;
        dType = std::numeric_limits<double>::infinity();
        std::cout << "double: " << dType << std::endl;
        return;
    }
    else if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        fType = std::numeric_limits<float>::quiet_NaN();
        std::cout << "float: " << fType << "f" << std::endl;
        dType = std::numeric_limits<double>::quiet_NaN();
        std::cout << "double: " << dType << std::endl;
        return;
    }

    if (iType > 32 && iType < 127)
    {
        cType = static_cast<char>(iType);
        std::cout << "char: '" << cType << "'" << std::endl;
    }
    else if ((iType >= 0 && iType <= 32) || iType == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Out of Range" << std::endl;

    if ((str.length() == 10 && str[str.length() - 1] > '7' && count == 0) || (str.length() > 10 && count == 0))
        std::cout << "int: impossible an OVERFLOW occurs" << std::endl;
    else
        std::cout << "int: " << iType << std::endl;
    std::string f;
    std::string d;

    if (count == 1 && flag == 0)
    {
        f = "f";
        d = "";
    }
    else if (count > 1)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else if (count == 0 || flag == 1)
    {
        f = ".0f";
        d = ".0";
    }
    fType = std::atof(str.c_str());
    // if (str.length() > 39)
    //     std::cout << "float: impossible an OVERFLOW occurs" << std::endl;
    // else
        std::cout << "float: " << fType << f << std::endl;

    dType = std::atof(str.c_str());
    std::cout << "double: " << dType << d << std::endl;
}