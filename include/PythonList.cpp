#include "PythonList.hpp"

pythonList::pythonList() {}

pythonList::pythonList(std::initializer_list<std::variant<int, double, std::string, bool>> initList) : data(initList) {}

void pythonList::append(std::variant<int, double, std::string, bool> item) {
    data.push_back(item);
}

void pythonList::append_at_index(std::variant<int, double, std::string, bool> item, size_t index) {
    if (index < data.size()) {
        data.insert(data.begin() + index, item);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

void pythonList::remove_item(std::variant<int, double, std::string, bool> item) {
    auto iter = std::find(data.begin(), data.end(), item);
    if (iter != data.end()) {
        data.erase(iter);
    }
}

void pythonList::remove_index(size_t index) {
    if (index < data.size()) {
        data.erase(data.begin() + index);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

std::variant<int, double, std::string, bool>& pythonList::operator[](size_t index) {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void pythonList::printIdx(size_t index) {
    if (index >= data.size()) {
        std::cout << "Index out of range" << std::endl;
    } else {
        std::visit([](const auto& value) {
            if constexpr (std::is_same_v<std::decay_t<decltype(value)>, bool>) {
                std::cout << (value ? "true" : "false");
            } else {
                std::cout << value;
            }
        }, data[index]);
    }
}

std::ostream& operator<<(std::ostream& os, const pythonList& myList) {
    for(const auto& variant : myList.data) {
        std::visit([&os](const auto& value){
            os << value;
        }, variant);
        os << " ";
    }
    return os;
}

template <typename T>
bool pythonList::search(T item) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (std::holds_alternative<T>(data[i]) && std::get<T>(data[i]) == item) {
            return true;
        }
    }
    return false;
}

size_t pythonList::size() const {
    return data.size();
}