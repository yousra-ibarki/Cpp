#include "Fixed.hpp"

    Fixed::Fixed(): fixed_point(0) {
        std::cout << "Default Constructor called" << std::endl;
    }
    Fixed::Fixed(const Fixed &new_obj){
        std::cout << "Copy Constructor called" << std::endl;
        *this = new_obj;
    }

    Fixed& Fixed::operator = (const Fixed &var){
        std::cout << "Copy Assignment Operator called" << std::endl;
        if(this != &var)
            fixed_point = var.fixed_point;
        return *this;
    }
    Fixed::~Fixed(){
        std::cout << "Destructor called" << std::endl;
    }
    Fixed::Fixed (const int var) {
        std::cout << "Int Constructor Called" << std::endl;
        fixed_point = var *  pow(2, fract_bit);
    }
    Fixed::Fixed (const float var1){
        std::cout << "Float Constructor Called" << std::endl;
        int integer;
        float fractional;
        float fixed_point1 ;
        fixed_point1 = var1 * pow(2, fract_bit);
        integer = (int)fixed_point1;
        fractional = (fixed_point1 - integer);        
        if(fractional >= 0.5)
            fixed_point = integer + 1;
        else
            fixed_point = integer;
    }


    int Fixed::getRawBits( void) const{
        std::cout << "getRawBits memeber function called" << std::endl;
        return fixed_point;
    }
    void Fixed::setRawBits(int const raw){
         std::cout << "getRawBits memeber function called" << std::endl;
        fixed_point = raw;
    }

    float Fixed::toFloat( void) const{
       return fixed_point / pow(2, fract_bit);
    }

    int Fixed::toInt( void )const{
       return fixed_point / pow(2, fract_bit);
    }
