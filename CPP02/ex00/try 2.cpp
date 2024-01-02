#include <iostream>
using namespace std;

class Length 
{
    private:
        int kmeter;            
        int meter;           

    public:

        Length() //default constructor 
        {
            kmeter = 0;
            meter = 0;
        }
        Length(int km, int m)  //overloaded constructor.
        {
            kmeter= km;
            meter = m;
        }
        void operator = (const Length &l) 
        { 
            kmeter = l.kmeter;
            meter = l.meter;
        }

        //method to display length.
        void displayLength() 
        {
            cout << kmeter << " Kms "<< meter << " meters" << endl;
        }
};

int main() 
{
    // Assigning by overloading contructor
    Length len1(1, 100);
    Length len2(2, 200);

    cout <<"Len1 length: "; 
    len1.displayLength();
   
    cout <<"Len2 length: "; 
    len2.displayLength();

    // overloading assignment operator to copy values
    len1 = len2;

    cout << "\nLen1 Length: "; 
    len1.displayLength();
    
    cout << "Len2 Length: "; 
    len2.displayLength();

    return 0;
}



Default constructor called 
Copy constructor called 
Copy assignment operator called   //<--Thislinemaybemissingdependingonyourimplementation 
get RawBits member function called 
Default  constructor called 
Copy assignment operator called
getRawBits member function called 
getRawBits member function called 
0 
getRawBits member function called 
0 
getRawBits member function called 
0 
Destructor called 
Destructor called 
Destructor called