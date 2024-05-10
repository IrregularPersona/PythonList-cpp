#ifndef PYTHON_LIST_HPP
#define PYTHON_LIST_HPP

#include <iostream>
#include <variant>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

class pythonList {
protected:
    std::vector<std::variant<int, double, std::string, bool>> data;

public:
    pythonList();
    pythonList(std::initializer_list<std::variant<int, double, std::string, bool>> initList);
    void append(std::variant<int, double, std::string, bool> item);
    void append_at_index(std::variant<int, double, std::string, bool> item, size_t index);
    void remove_item(std::variant<int, double, std::string, bool> item);
    void remove_index(size_t index);
    std::variant<int, double, std::string, bool>& operator[](size_t index);
    void printIdx(size_t index);
    template <typename T> bool search(T item);
    size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const pythonList& myList);
};

#endif
