#include <iostream>
#include <string>
#include "include/PythonList.hpp"

int main() {

    pythonList myList = {10, 20.5, "Hello World!"};

    for(int i = 0; i < myList.size(); i++){
        myList.printIdx(i);
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

    myList.append("JASON KONTOL");
    myList.append("MEMEK");
    myList.append("ASU");

    for(int i = 0; i < myList.size(); i++){
        myList.printIdx(i);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}