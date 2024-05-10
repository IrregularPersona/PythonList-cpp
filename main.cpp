#include <iostream>
#include <string>
#include "include/PythonList.hpp"

int main() {

    pythonList myList = {10, 20.5, "Hello World!", true, false};

    for(int i = 0; i < myList.size(); i++){
        myList.print(i);
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

    for(int i = 0; i < myList.size(); i++){
        myList.print(i);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int i = 0; i < myList.size(); i++) {
        std::cout << myList[i] << std::endl;
    }

    myList.print();
}