#include "BitcoinExchange.hpp"
//.
Bitcoin::Bitcoin()
{
}

Bitcoin::~Bitcoin()
{
}

Bitcoin::Bitcoin(const Bitcoin &obj)
{
    *this = obj;
}

Bitcoin &Bitcoin::operator=(const Bitcoin &obj)
{
    if (this == &obj)
        return *this;
    else
    {
        this->data = obj.data;
        this->it = obj.it;
        this->line = obj.line;
    }
    return *this;
}

std::string Bitcoin::removeSpace(std::string str)
{
    std::string result;

    bool spaceFound = false;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if (*it == ' ')
        {
            if (!spaceFound)
            {
                result += *it;
                spaceFound = true;
            }
        }
        else
        {
            result += *it;
            spaceFound = false;
        }
    }
    return result;
}

bool Bitcoin::isnumber(std::string str)
{
    for (unsigned long i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

std::map<std::string, std::string> Bitcoin::split(std::string str)
{
    this->file.open(str);
    std::string tokenValue;
    std::string tokenKey;
    if (this->file.is_open())
    {
        while (this->file.eof() == false)
        {
            std::getline(this->file, this->line);
            std::istringstream iss(line);
            this->it = data.begin();
            getline(iss, tokenValue, ',');
            getline(iss, tokenKey, ',');
            data[tokenValue] = tokenKey;
        }
        file.close();
        return this->data;
    }
    else
    {
        std::cerr << "cannot open the file" << std::endl;
        exit(1);
    }
}

int Bitcoin::checkDate(std::string &date)
{
    int yr = 0;
    int mo = 0;
    int dy = 0;

    // std::string year;
    // std::string month;
    // std::string day;

    int leap = 0;
    char delimiter;
    std::istringstream iss(date);
    if (!(iss >> yr >> delimiter >> mo >> delimiter >> dy))
    {
        return 0;
    }
    std::stringstream ss;
    ss << yr;
    year = ss.str();

    if (yr < 0 || mo < 1 || mo > 12 || dy < 1 || dy > 31 || year.length() != 4)
    {
        return 0;
    }

    if (mo % 2 != 0 && dy > 30)
    {
        return 0;
    }

    if (mo == 2)
    {
        leap = (yr % 4 == 0 && (yr % 100 != 0 || yr % 400 == 0));
        if ((leap && dy > 29) || (!leap && dy > 28))
        {
            return 0;
        }
    }
    return 1;
}

double Bitcoin::getValue(std::string &date)
{
    std::map<std::string, std::string>::iterator it = data.lower_bound(date);
    if (it->first != date && it != data.begin())
    {
        --it;
    }
    if (it != data.end())
    {
        rate = atof(it->second.c_str());
        return rate;
    }
    else if (!data.empty())
    {
        rate = atof(it->second.c_str());
        return rate;
    }
    return -1;
}
int Bitcoin::checkValue(double value, std::string &date)
{
    if (value < 0)
    {
        return 2;
    }
    else if (value > 1000)
    {
        return 3;
    }
    rate = getValue(date);
    if (rate == -1)
    {
        return 0;
    }
    return 1;
}

int Bitcoin::ft_check(std::string line)
{
    // std::cout << "lien = " << line << std::endl;
    int count = 0;
    std::string tmp;

    std::istringstream pa(line);

    std::getline(pa, tokenKey, '|');
    std::getline(pa, tokenValue, '|');
    std::getline(pa, tmp, '|');

    if (tmp != "\0")
        return 0;

    for (int i = 0; tokenValue[i]; i++)
    {
        if (tokenValue[i] == '.')
            count++;
        if (count > 1)
            return 0;
    }

    std::istringstream par(tokenKey);
    std::getline(par, year, '-');
    std::getline(par, month, '-');
    std::getline(par, day, '-');
    day = removeSpace(day);
    year = removeSpace(year);

    if (day[day.size() - 1] == ' ')
    {
        day.erase(day.size() - 1);
    }
    if (year[0] == ' ')
        year.erase(year.begin() + 1);

    if (year.length() != 4 || !isnumber(year))
        return 0;
    if (month.length() != 2 || !isnumber(month))
        return 0;
    if (day.length() != 2 || !isnumber(day))
    {
        return 0;
    }

    return 1;
}

void Bitcoin::pars(char *str)
{
    std::ifstream file2;
    std::string date;
    double value;
    char pip;
    std::string first, second;
    file2.open(str);
    if (file2.is_open())
    {
        std::getline(file2, this->line);
        line = removeSpace(line);
        std::istringstream format(line);
        std::getline(format, first, '|');
        std::getline(format, second, '|');
        if (first != " date " && first != " date" && first != "date " && first != "date")
        {
            std::cerr << "Error => " << line << std::endl;
            exit(1);
        }
        if (second != " value " && second != " value" && second != "value " && second != "value")
        {
            std::cerr << "Error => " << line << std::endl;
            exit(1);
        }
        while (std::getline(file2, this->line))
        {
            if (ft_check(line) == 0)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            std::istringstream iss(line);
            if (!(iss >> date >> pip >> value))
            {
                std::cerr << "Error: Bad Input => " << this->line << std::endl;
                continue;
            }
            if (pip == '|')
            {
                if (checkDate(date) == 1 && checkValue(value, date) == 1)
                {
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                }
                else if (checkValue(value, date) == 2)
                {
                    std::cerr << "Error: not a positive number" << std::endl;
                    continue;
                }
                else if (checkValue(value, date) == 3)
                {
                    std::cerr << "Error: too large number" << std::endl;
                    continue;
                }
                else
                {
                    std::cerr << "Error: Bad Input => " << line << std::endl;
                    continue;
                }
            }
            else
            {
                std::cerr << "Error: Bad Input => " << line << std::endl;
                continue;
            }
        }
    }
    else
        std::cout << "No such file" << std::endl;
}
