#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
    int fixed_point;
    static const int fract_bit = 8;
public:
    Fixed();
    Fixed(Fixed &new_obj);
    Fixed& operator= (const Fixed &var);
    ~Fixed();
    Fixed (const int var);
    Fixed (const float var1);
    int getRawBits( void) const;
    void setRawBits(int const raw);
    float toFloat( void) const;
    int toInt( void )const;
};


#endif