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
    Fixed (const int var);
    Fixed (const float var1);
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
    
    // Fixed operator++ (int);
    // Fixed operator ++ ();
    // Fixed operator-- ();
    // Fixed operator-- (int);
    
    static int& min(int& fixed1, int &fixed2);
    static int& max(int& fixed1, int &fixed2);

};

#endif

// MyClass operator++(int) {
//     MyClass temp(*this);  // Create a copy of the original object
//     ++value;             // Increment the object's value
//     return temp;         // Return the original object's value before the increment
// }