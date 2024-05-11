#ifndef PYTHON_LIST_HPP
#define PYTHON_LIST_HPP


#include <iostream>
#include <variant>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <cstddef>

enum class SortOrder { Ascending, Descending };

class pythonList {
protected:
    std::vector<std::variant<int, double, std::string, bool>> data;

public:
    pythonList();
    pythonList(std::initializer_list<std::variant<int, double, std::string, bool>> initList);
    std::variant<int, double, std::string, bool>& operator[](size_t index);
    friend std::ostream& operator<<(std::ostream& os, const pythonList& myList);
    template <typename T> bool find(T item);
    template <typename T> size_t index(T item);
    template <typename T> size_t count(T item);
    void append(std::variant<int, double, std::string, bool> item);
    void clear();
    void copy(pythonList& originList, pythonList& copyList);
    void extend(pythonList& destList, pythonList& srcList);
    void insert(size_t index, std::variant<int, double, std::string, bool> item);
    void pop(size_t index);
    void print();
    void print(size_t index);
    void remove(std::variant<int, double, std::string, bool> item);
    void reverse();
    void reverse(size_t startIndex, size_t endIndex);
    void sort();
    void sort(SortOrder order);
    void sort(SortOrder order, size_t startIndex, size_t endIndex);
    size_t size() const;

    /*
        - make an extend method
        - make an index method
        - make a count method
        - make a copy method
        - make a clear method
    */
};

inline std::ostream& operator<<(std::ostream& os, const std::variant<int, double, std::string, bool>& var) {
    std::visit([&os](const auto& value) { os << value; }, var);
    return os;
}

#endif
