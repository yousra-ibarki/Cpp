#include "Fixed.hpp"


//Default Constructor
    Fixed::Fixed(): fixed_point(0) {
        std::cout << "Default Constructor called\n";
    }
// Copy Constructor
    Fixed::Fixed(Fixed &new_obj){
        std::cout << "Copy Constructor called\n";
        fixed_point = new_obj.fixed_point;
    }

    //a copy assignment operator overload is just a correction of 
    //the default behavior of the shallow copying which lead to 
    //the double free and leaks 
    Fixed&Fixed:: operator= (const Fixed &var){
        std::cout << "Copy Assignment Operator called\n";
        //this->fixed_point = var.fixed_point;  //copying fixed point of a in fixed point of b
        fixed_point = var.fixed_point;
        return *this;
    }
    Fixed::~Fixed(){
        std::cout << "Destructor called\n";
        // delete var;
    }
//Int Constructor
    Fixed::Fixed (const int var) {
        std::cout << "Int Constructor Called\n";
        fixed_point = var *  pow(2, fract_bit);
       // std::cout << fixed_point << std::endl;
    }
// Float Constructor
    Fixed::Fixed (const float var1){
        std::cout << "Float Constructor Called\n";
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
        //std::cout << "result : " << fixed_point << std::endl;
    }


    int Fixed::getRawBits( void) const{
        std::cout << "getRawBits memeber function called\n";
        return fixed_point;
    }
    void Fixed::setRawBits(int const raw){
         std::cout << "getRawBits memeber function called\n";
        fixed_point = raw;
    }

    float Fixed::toFloat( void) const{
       return fixed_point / pow(2, fract_bit);
    }

    int Fixed::toInt( void )const{
       return fixed_point / pow(2, fract_bit);
    }
