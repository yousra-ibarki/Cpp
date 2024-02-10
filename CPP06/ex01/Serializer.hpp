#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Serializer{
private:
    typedef struct s_Data{
        int iType;
        float fType;
        double dType;
        char cType;
    } Data;
public:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& obj);
    Serializer& operator=(const Serializer& obj);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif