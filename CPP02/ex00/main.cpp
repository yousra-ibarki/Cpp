#include <iostream>

class OCF{
private:
    int fixed_point;
    static const int fract_bit = 8;
public:
    OCF(): fixed_point(0) {
        std::cout << "Default Constructor\n";
    }
    OCF(OCF &new_obj){
        std::cout << "Copy Constructor\n";
        fixed_point = new_obj.fixed_point;
    }
    //a copy assignment operator overload is just a correction of 
    //the default behavior of the shallow copying which lead to 
    //the double free and leaks 
    OCF& operator= (const OCF &var){
        std::cout << "Copy Assignment Operator\n";
        //this->fixed_point = var.fixed_point;  //copying fixed point of a in fixed point of b
        fixed_point = var.fixed_point;
    }




    ~OCF(){
        std::cout << "Destructor\n";
        // delete var;
    }



};


int main()
{
    OCF a;
    OCF b;
    OCF c;

    a = b;  // means a.operator= (b);
}