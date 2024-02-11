#include "Serializer.hpp"

Serializer::Serializer(){
    std::cout << "Constructor Called" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Destructor Called" << std::endl;
}

Serializer::Serializer(const Serializer& obj){
    *this = obj;
}

Serializer& Serializer::operator=(const Serializer& obj){
    if(this != &obj)
    {
        this->data.iType = obj.data.iType;
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
 
 
// Data* Serializer::deserializ(uintptr_t raw){

// }
