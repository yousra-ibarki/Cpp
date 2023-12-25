#include <iostream>
#include <cmath>

class Fixed{
private:
    int fixed_point;
    static const int fract_bit = 8;
public:
//Default Constructor
    Fixed(): fixed_point(0) {
        std::cout << "Default Constructor called\n";
    }
// Copy Constructor
    Fixed(Fixed &new_obj){
        std::cout << "Copy Constructor called\n";
        fixed_point = new_obj.fixed_point;
    }
//Int Constructor
    Fixed (const int var) {
        std::cout << "Int Constructor Called\n";
        fixed_point = var *  pow(2, fract_bit);
       // std::cout << fixed_point << std::endl;
    }
// Float Constructor
    Fixed (const float var1){
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

    Fixed& operator= (const Fixed &var){
    //a copy assignment operator overload is just a correction of 
    //the default behavior of the shallow copying which lead to 
    //the double free and leaks 
        std::cout << "Copy Assignment Operator called\n";
        //this->fixed_point = var.fixed_point;  //copying fixed point of a in fixed point of b
        fixed_point = var.fixed_point;
        return *this;
    }

    ~Fixed(){
        std::cout << "Destructor called\n";
        // delete var;
    }
    int getRawBits( void) const{
        std::cout << "getRawBits memeber function called\n";
        return fixed_point;
    }
    void setRawBits(int const raw){
         std::cout << "getRawBits memeber function called\n";
        fixed_point = raw;
    }

    float toFloat( void) const{
       return fixed_point / pow(2, fract_bit);
    }

    int toInt( void )const{
       return fixed_point / pow(2, fract_bit);
    }
};

std::ostream& operator<<(std::ostream& c, const Fixed& object){
    c << "" << object.toFloat() << "";
    return c;
}


int main( void )
{ 
    Fixed a; 
    Fixed const b(10); 
    Fixed const c(42.42f); 
    Fixed const d(b); 

    a = Fixed(1234.4321f); 

    std::cout << "a is " << a <<std::endl; 
    std::cout << "b is " << b <<std::endl; 
    std::cout << "c is " << c <<std::endl; 
    std::cout << "d is " << d <<std::endl; 

    std::cout << "a is " << a.toInt()<< " as integer"<<std::endl; 
    std::cout << "b is " << b.toInt()<< " as integer"<<std::endl; 
    std::cout << "c is " << c.toInt()<< " as integer"<<std::endl; 
    std::cout << "d is " << d.toInt()<< " as integer"<<std::endl; 
    return 0; 
}