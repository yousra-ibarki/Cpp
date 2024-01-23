#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void function(){
    system("leaks IDontWantToSetTheWorldOnFire");
}

// int main() 
// {
//     //atexit(function);
//     Animal* arr[10];
//     int i;
//     for(i = 0; i < 5; i++){
//         arr[i] = new Dog();
//     }
//     for(int j = i; j < 10; j++){
//         arr[j] = new Cat();
//     }
//     for(i = 0; i < 10; i++){
//         delete arr[i];
//     }
//  return 0;
// }
    
  int main()
{
    atexit(function);
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;

  //  while(1);
    return 0;
}
