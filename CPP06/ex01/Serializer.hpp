#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

class Serializer{
private:

    Serializer();
    Serializer(const Serializer& obj);
    Serializer& operator=(const Serializer& obj);
public:
    typedef struct s_Data{
        int iType;
        float fType;
        double dType;
        char cType;
    } Data;
    Data data;
    ~Serializer();
    static Data* deserialize(uintptr_t raw){
        return reinterpret_cast<Data*>(raw);
    }
    static uintptr_t serialize(Data* ptr);

};

#endif