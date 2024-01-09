#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
private:
    int fixed_point;
    static const int fract_bit = 8;
public:
    Fixed();
    Fixed(Fixed &new_obj);
    Fixed& operator= (const Fixed &var);
    ~Fixed();
    int getRawBits( void) const;
    void setRawBits(int const raw);
};


#endif