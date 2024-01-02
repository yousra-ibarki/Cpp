#include <iostream>

class Fixed{
private:
    int fixed_point;
    static const int fract_bit = 8;
public:
    Fixed(): fixed_point(0) {
        std::cout << "Default Constructor called\n";
    }
    Fixed(Fixed &new_obj){
        std::cout << "Copy Constructor called\n";
        fixed_point = new_obj.fixed_point;
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
    Fixed b(a); 
    Fixed c; 
    c=b; 
    std::cout<<a.getRawBits() << std::endl; 
    std::cout<<b.getRawBits() << std::endl; 
    std::cout<<c.getRawBits() << std::endl; 
    return 0; 
    }