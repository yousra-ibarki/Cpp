#include <iostream>

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

    bool operator> (const Fixed& obj){
        return fixed_point > obj.fixed_point; 
    }

    bool operator< (const Fixed& obj){
        return fixed_point < obj.fixed_point;
    }

    bool operator>= (const Fixed& obj){
        return fixed_point >= obj.fixed_point;
    }

    bool operator<= (const Fixed& obj){
        return fixed_point <= obj.fixed_point;
    }

    bool operator== (const Fixed& obj){
        return fixed_point == obj.fixed_point;
    }

    bool operator!= (const Fixed& obj){
        return fixed_point != obj.fixed_point;
    }
    
    Fixed operator* (const Fixed& obj1){
        return (this->fixed_point * obj1.fixed_point);
    }

    // Fixed operator+ (const Fixed& obj1){
    //     return(this->fixed_point + obj1.fixed_point);
    // }

    // Fixed operator- (const Fixed& obj1){
    //     return(this->fixed_point - obj1.fixed_point);
    // }

    // Fixed operator/ (const Fixed& obj1){
    //     return(this->fixed_point / obj1.fixed_point);
    // }

    Fixed operator++ (int){
        Fixed obj;
        obj.fixed_point = fixed_point++;
        return obj;
    }

    Fixed operator ++ (){
        Fixed obj;
        obj.fixed_point = ++fixed_point;
        return obj;
    }
    Fixed operator-- (){
        Fixed obj;
        obj.fixed_point = --fixed_point;
        return obj;
    }
    Fixed operator-- (int){
        Fixed obj;
        obj.fixed_point = fixed_point--;
        return obj;
    }

    static int& min(int& fixed1, int &fixed2){
        if(fixed1 <= fixed2)
            return fixed1;
        else
            return fixed2;
    }

    static int& max(int& fixed1, int &fixed2){
        if(fixed1 <= fixed2)
            return fixed2;
        else
            return fixed1;
    }

};

std::ostream& operator<<(std::ostream& c, const Fixed& object){
    c << "" << object.toFloat() << "";
    return c;
}


int main( void ) {
Fixed a;
Fixed const b(Fixed(5.05f) * Fixed(2));
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
// std::cout << Fixed::max(a, b) << std::endl;
return 0;
}

