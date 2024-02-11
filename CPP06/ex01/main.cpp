#include "Serializer.hpp"

int main()
{
    Serializer::Data* data;
    Serializer::Data* out;
    uintptr_t nbr;
    data = new Serializer::Data;
    std::cout << data << std::endl;
    nbr = Serializer::serialize(data);
    std::cout << nbr << std::endl;
    out = Serializer::deserialize(nbr);
    std::cout << out << std::endl;


}