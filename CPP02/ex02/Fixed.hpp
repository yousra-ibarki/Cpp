#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
private:
    static const int fract_bit = 8;
public:
    int fixed_point;
    Fixed();
    Fixed(const Fixed &new_obj);
    Fixed (const int& var);
    Fixed (const float& var1);
    Fixed& operator= (const Fixed &var);
    ~Fixed();

    int getRawBits( void) const;
    void setRawBits(int const raw);

    float toFloat( void) const;
    int toInt( void )const;

    bool operator> (const Fixed& obj);
    bool operator< (const Fixed& obj);
    bool operator>= (const Fixed& obj);
    bool operator<= (const Fixed& obj);

    bool operator== (const Fixed& obj);
    bool operator!= (const Fixed& obj);

    Fixed operator* (const Fixed& obj1);
    Fixed operator+ (const Fixed& obj1);
    Fixed operator- (const Fixed& obj1);
    Fixed operator/ (const Fixed& obj1);
    Fixed operator++ (int);
    Fixed &operator++ ();
    Fixed &operator-- ();
    Fixed operator-- (int);
    
    static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
    static const Fixed& min(const Fixed& obj1, const Fixed& obj2);

    static Fixed& max(Fixed& obj1, Fixed& obj2);
    static Fixed& min(Fixed& obj1, Fixed& obj2);

};

#endif
