#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"




int main() 
{
    // Animal* arr[100];
    // int i;
    // for(i = 0; i < 50; i++){
    //     arr[i] = new Dog();
    // }
    // for(int j = i; j < 100; j++){
    //     arr[j] = new Cat();
    // }
    // for(i = 0; i < 100; i++){
    //     delete arr[i];
    // }
    

    const Animal*j= new Dog(); 
    const Animal*i= new Cat(); 
    delete j; //should not create a leak 
    delete i; 
  //  while(1);
    return 0;
}
