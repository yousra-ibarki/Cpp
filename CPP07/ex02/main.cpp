// #include "Array.hpp"

// int main()
// {

//     try
//     {
//         std::cout << std::endl;
//         Array<int> arr(6);
//         Array<std::string> arrS(6);

//         arr[0] = 5;
//         arr[1] = 10;
//         arr[2] = 86;
//         arr[3] = 23;
//         arr[4] = 235;
//         arr[5] = 345;

//         arrS[0] = "A";
//         arrS[1] = "B";
//         arrS[2] = "C";
//         arrS[3] = "D";
//         arrS[4] = "E";
//         arrS[5] = "F";

//         for (unsigned int i = 0; i < arr.size(); i++)
//         {
//             std::cout << "arr1[" << i << "] = " << arr[i] << std::endl;
//         }

//         std::cout << std::endl;
//         for (unsigned int i = 0; i < arrS.size(); i++)
//         {
//             std::cout << "arr2[" << i << "] = " << arrS[i] << std::endl;
//         }

//         std::cout << std::endl;

//         Array<std::string> copy(arrS);

//         arrS[2] = "Hello";

//         for (std::size_t i = 0; i < arrS.size(); ++i)
//         {
//             std::cout << arrS[i] << std::endl;
//         }
//         std::cout << std::endl;

//         for (std::size_t i = 0; i < copy.size(); ++i)
//         {
//             std::cout << copy[i] << std::endl;
//         }
//     }
//     catch (std::exception &e)
//     {
//         std::cout << e.what() << std::endl;
//     }

//     try
//     {
//         Array<double> arr(6);
//         std::cout << std::endl;
//         std::cout << arr[-31] << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}