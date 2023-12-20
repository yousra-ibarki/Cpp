#include <iostream>

class AB {
public:
   int sub(int a, int b) {
      return a-b;
   }
   int div(int a, int b) {
      return a/b;
   }

};
//using function pointer
int res1(int m, int n, AB* obj, int(AB::*fp)(int,int)) {
   return (obj->*fp)(m,n);
}

//using function pointer
int res2(int m, int n, AB* obj, int(AB::*fp2)(int,int)) {
   return (obj->*fp2)(m,n);
}

int main() {
   AB ob;
   std::cout << "Subtraction is = " << res1(8,5, &ob, &AB::sub) << std::endl;
   std::cout << "Division is = " << res2(4,2, &ob, &AB::div) << std::endl;
   return 0;
}
#include <iostream>

class MyClass {
private:
    void function1() {
        std::cout << "Function 1" << std::endl;
    }

    void function2() {
        std::cout << "Function 2" << std::endl;
    }

    void function3() {
        std::cout << "Function 3" << std::endl;
    }

    void function4() {
        std::cout << "Function 4" << std::endl;
    }

public:
    typedef void (MyClass::*FunctionPtr)(); // Define function pointer type

    FunctionPtr func1Ptr;
    FunctionPtr func2Ptr;
    FunctionPtr func3Ptr;
    FunctionPtr func4Ptr;

    MyClass() {
        // Assign function pointers in constructor
        func1Ptr = &MyClass::function1;
        func2Ptr = &MyClass::function2;
        func3Ptr = &MyClass::function3;
        func4Ptr = &MyClass::function4;
    }

    void callFunction(const std::string& functionName) {
        FunctionPtr chosenFuncPtr;

        // Determine which function pointer to call based on the function name
        if (functionName == "function1")
            chosenFuncPtr = func1Ptr;
        else if (functionName == "function2")
            chosenFuncPtr = func2Ptr;
        else if (functionName == "function3")
            chosenFuncPtr = func3Ptr;
        else if (functionName == "function4")
            chosenFuncPtr = func4Ptr;
        else {
            std::cout << "Invalid function name" << std::endl;
            return;
        }

        // Call the chosen function pointer
        (this->*chosenFuncPtr)();
    }
};

int main() {
    MyClass myObject;
    myObject.callFunction("function1"); // Output: Function 1
    myObject.callFunction("function3"); // Output: Function 3
    myObject.callFunction("function2"); // Output: Function 2
    myObject.callFunction("function4"); // Output: Function 4
    myObject.callFunction("invalid");   // Output: Invalid function name

    return 0;
}


typedef void (*FuncPtr)(int);  // creates a new name 'FuncPtr' for the function pointer type void(*)(int)

void printNumber(int num) {
    printf("%d\n", num);
}

void performOperation(FuncPtr operation, int num) {
    operation(num);
}

int main() {
    FuncPtr func = &printNumber;  // declaring a function pointer variable using the typedef

    performOperation(func, 5);  // using the function pointer

    return 0;
}