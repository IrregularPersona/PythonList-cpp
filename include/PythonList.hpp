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
    void append(std::variant<int, double, std::string, bool> item);
    void append_at_index(std::variant<int, double, std::string, bool> item, size_t index);
    void remove_item(std::variant<int, double, std::string, bool> item);
    void remove_index(size_t index);
    std::variant<int, double, std::string, bool>& operator[](size_t index);
    void print();
    void print(size_t index);
    template <typename T> bool search(T item);
    size_t size() const;
    void reverse();
    void reverse(size_t startIndex, size_t endIndex);
    void sort();
    void sort(SortOrder order);
    void sort(SortOrder order, size_t startIndex, size_t endIndex);

    friend std::ostream& operator<<(std::ostream& os, const pythonList& myList);
};

inline std::ostream& operator<<(std::ostream& os, const std::variant<int, double, std::string, bool>& var) {
    std::visit([&os](const auto& value) { os << value; }, var);
    return os;
}

#endif
