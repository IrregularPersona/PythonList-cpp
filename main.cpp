#include <iostream>
#include <string>
#include "include/PythonList.hpp"

void menu() {
    std::cout << "1 -> int\n";
    std::cout << "2 -> double\n";
    std::cout << "3 -> string\n";
    std::cout << "4 -> bool\n";
}

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