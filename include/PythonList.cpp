#include "PythonList.hpp"

pythonList::pythonList() {}

pythonList::pythonList(std::initializer_list<std::variant<int, double, std::string, bool>> initList) : data(initList) {}

void pythonList::append(std::variant<int, double, std::string, bool> item) {
    data.push_back(item);
}

void pythonList::insert(size_t index, std::variant<int, double, std::string, bool> item) {
    if (index <= data.size() && index > 0) {
        data.insert(data.begin() + index, item);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

void pythonList::remove(std::variant<int, double, std::string, bool> item) {
    auto iter = std::find(data.begin(), data.end(), item);
    if (iter != data.end()) {
        data.erase(iter);
    }
}

void pythonList::pop(size_t index) {
    if (index < data.size()) {
        data.erase(data.begin() + index);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

void pythonList::clear() {
    
    data.clear();
    
}

void pythonList::copy(pythonList& originList, pythonList& copyList) {
    
    copyList.clear();

    for(size_t i = 0; i < originList.size(); i++) {
        copyList.append(originList[i]);
    }

}

void pythonList::extend(pythonList& destList, pythonList& srcList) {
    
    if(destList.size() <= 0) { throw std::length_error("Destination list is empty!"); }
    if(srcList.size() <= 0) { throw std::length_error("Source list is empty!"); }
    
    for(size_t i = 0; i < data.size(); i++) {
        destList.append(srcList[i]);
    }
}

std::variant<int, double, std::string, bool>& pythonList::operator[](size_t index) {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void pythonList::print() {
    if(data.size() == 0) {
        std::cerr << "List empty!\n";
        return;
    } else {
        for(const auto& element : data) {
            std::visit([](const auto& value) {
                if constexpr (std::is_same_v<std::decay_t<decltype(value)>, bool>) {
                    std::cout << (value ? "true" : "false") << " ";
                } else if constexpr (std::is_same_v<std::decay_t<decltype(value)>, std::string>) {
                    std::cout << "\'" << value << "\'" << " ";
                } else {
                    std::cout << value << " ";
                }
            }, element);
        }
        std::cout << std::endl;
    }
}


void pythonList::print(size_t index) {
    if (index >= data.size()) {
        std::cout << "Index out of range" << std::endl;
    } else {
        std::visit([](const auto& value) {
            if constexpr (std::is_same_v<std::decay_t<decltype(value)>, bool>) {
                std::cout << (value ? "true" : "false");
            } else if constexpr (std::is_same_v<std::decay_t<decltype(value)>, std::string>) {
                std::cout << "\'" << value << "\'";
            } else {
                std::cout << value;
            }
        }, data[index]);
    }
}

void pythonList::reverse() {
    std::reverse(data.begin(), data.end());
}

void pythonList::reverse(size_t startIndex, size_t endIndex) {
    std::reverse(data.begin() + startIndex, data.end() + endIndex);
}

void pythonList::sort() {
    std::sort(data.begin(), data.end());
}

void pythonList::sort(SortOrder order) {
    if (order == SortOrder::Ascending) {
        std::sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
            return a < b;
        });
    } else if (order == SortOrder::Descending) {
        std::sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
            return a > b;
        });
    } else {
        std::cerr << "Invalid sort order specified." << std::endl;
    }
}

void pythonList::sort(SortOrder order, size_t startIndex, size_t endIndex) {
    if (startIndex >= endIndex || endIndex > data.size()) {
        std::cerr << "Invalid range specified for sorting." << std::endl;
        return;
    }

    if (order == SortOrder::Ascending) {
        std::sort(data.begin() + startIndex, data.begin() + endIndex, [](const auto& a, const auto& b) {
            return a < b;
        });
    } else if (order == SortOrder::Descending) {
        std::sort(data.begin() + startIndex, data.begin() + endIndex, [](const auto& a, const auto& b) {
            return a > b;
        });
    } else {
        std::cerr << "Invalid sort order specified." << std::endl;
    }
}

template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::variant<Ts...>& var) {
    std::visit([&os](const auto& value) { os << value; }, var);
    return os;
}

template <typename T> size_t pythonList::count(T item) {
    if(data.size() <= 0) { throw std::length_error("List is empty!"); }
    else {
        size_t itemCount = 0;
        for(size_t i = 0; i < data.size(); i++) {
            if(std::holds_alternative<T>(data[i]) && std::get<T>(data[i]) == item) {
                itemCount++;
            }
        }
        return itemCount;
    }
    return -1;
}

template<typename T>
size_t pythonList::index(T item) {
    if(data.size() <= 0) {
        throw std::length_error("List is empty!");
    } else {
        for(size_t i = 0; i < data.size(); i++) {
            if(std::holds_alternative<T>(data[i]) && std::get<T>(data[i]) == item) {
                return i;
            } 
        }
    }
    return -1;
}

template <typename T>
bool pythonList::find(T item) {
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

