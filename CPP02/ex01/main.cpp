#include <iostream>

class Fixed{
private:
    int fixed_point;
    static const int fract_bit = 8;
public:
    Fixed (const int var) {
        fixed_point = var;
    }
    Fixed (const float var1){

    }
    Fixed(): fixed_point(0) {
        std::cout << "Default Constructor called\n";
    }
    Fixed(Fixed &new_obj){
        std::cout << "Copy Constructor called\n";
        fixed_point = new_obj.fixed_point;
    }

    float toFloat( void) const{
        //converting fixed point value to floating point value;
    }

    int toInt( void )const{
        //converting the fixed point to int 
    }


    //a copy assignment operator overload is just a correction of 
    //the default behavior of the shallow copying which lead to 
    //the double free and leaks 
    Fixed& operator= (const Fixed &var){
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
        // std::cout << "getRawBits memeber function called\n";
        fixed_point = raw;
    }



};


int main( void )
{ 
    Fixed a; 
    Fixed const b(10); 
    Fixed const c(42.42f); 
    Fixed const d(b); 
    a = Fixed(1234.4321f); 
    std::cout << "ais" << a<<std::endl; 
    std::cout << "bis" << b<<std::endl; 
    std::cout <<"cis" << c<<std::endl; 
    std::cout <<"dis" << d<<std::endl; 
    std::cout <<"ais" << a.toInt()<< "asinteger"<<std::endl; 
    std::cout <<"bis" << b.toInt()<< "asinteger"<<std::endl; 
    std::cout <<"cis" << c.toInt()<< "asinteger"<<std::endl; 
    std::cout <<"dis" << d.toInt()<< "asinteger"<<std::endl; 
    return 0; 
}