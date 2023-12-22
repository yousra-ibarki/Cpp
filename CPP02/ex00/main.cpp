#include <iostream>

class OCF{
private:
    int fixed_point;
    static const int fract_bit = 8;
public:
    //a default constructor
    OCF(): fixed_point(0) {}
    //a copy constructor
    OCF(OCF &new_obj){
        fixed_point = new_obj.fixed_point;
    }
    //a copy assignment operator overload
    



};


int main()
{

}