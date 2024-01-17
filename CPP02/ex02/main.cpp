#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
}

Fixed::Fixed(const Fixed &new_obj)
{
    fixed_point = new_obj.fixed_point;
}

Fixed::Fixed(const int &var)
{
    this->fixed_point = var * pow(2, fract_bit);
}

Fixed::Fixed(const float &nbr)
{
    std::cout << "Float Constructor Called" << std::endl;
    fixed_point = roundf(nbr * pow(2, fract_bit));
}

Fixed &Fixed::operator=(const Fixed &var)
{
    fixed_point = var.fixed_point;
    return *this;
}

Fixed::~Fixed()
{
}
int Fixed::getRawBits(void) const
{
    return fixed_point;
}
void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return fixed_point / pow(2, fract_bit);
}

int Fixed::toInt(void) const
{
    return fixed_point / pow(2, fract_bit);
}

bool Fixed::operator>(const Fixed &obj)
{
    return fixed_point > obj.fixed_point;
}

bool Fixed::operator<(const Fixed &obj)
{
    return fixed_point < obj.fixed_point;
}

bool Fixed::operator>=(const Fixed &obj)
{
    return fixed_point >= obj.fixed_point;
}

bool Fixed::operator<=(const Fixed &obj)
{
    return fixed_point <= obj.fixed_point;
}

bool Fixed::operator==(const Fixed &obj)
{
    return fixed_point == obj.fixed_point;
}

bool Fixed::operator!=(const Fixed &obj)
{
    return fixed_point != obj.fixed_point;
}

Fixed Fixed::operator*(const Fixed &obj1)
{
    Fixed tmp(obj1.toFloat() * this->toFloat());

    // this->fixed_point = this->fixed_point * obj1.fixed_point;
    return tmp;
}

Fixed Fixed::operator+(const Fixed &obj1)
{
    Fixed tmp;
    tmp.fixed_point = this->fixed_point + obj1.fixed_point;
    return tmp;
}

Fixed Fixed::operator-(const Fixed &obj1)
{
    Fixed tmp;
    tmp.fixed_point = this->fixed_point - obj1.fixed_point;
    return tmp;
}

Fixed Fixed::operator/( Fixed &obj1) const
{
    Fixed tmp;
    tmp.fixed_point = this->fixed_point / obj1.fixed_point;
    return tmp;
}

Fixed &Fixed::Fixed::operator++()
{
    ++(this->fixed_point);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    (this->fixed_point)++;
    return tmp;
}

Fixed &Fixed::operator--()
{
    --(this->fixed_point);
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    (tmp.fixed_point)--;
    return tmp;
}

Fixed Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1.fixed_point > obj2.fixed_point)
        return obj2;
    else
        return obj1;
}

Fixed Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1.fixed_point > obj2.fixed_point)
        return obj1;
    else
        return obj2;
}

std::ostream &operator<<(std::ostream &c, const Fixed &object)
{
    c << object.toFloat();
    return c;
}

int main(void)
{
    Fixed a(1.3f);
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << b / a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}
