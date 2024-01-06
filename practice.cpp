#include <iostream>

using namespace std;

class ROFT{
private:
    int *data;
public:
    ROFT(){
        data = new int(0);
    }

    ~ROFT(){
        delete data;
    }

    void set_value(int value){
        *data = value;
    }

    int *get_value(){
        return(data);
    }
};

int main()
{
    ROFT obj_1;
    obj_1.set_value(1337);
    ROFT obj_2 = obj_1;
    obj_1.set_value(34);

    cout << "First Objet: " << *obj_1.get_value() << " Second Objet: " << *obj_2.get_value() << endl;
}
