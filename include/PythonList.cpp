#include "PythonList.hpp"

pythonList::pythonList() {}

pythonList::pythonList(std::initializer_list<std::variant<int, double, std::string, bool>> initList) : data(initList) {}

void pythonList::append(std::variant<int, double, std::string, bool> item) {
    data.push_back(item);
}

void pythonList::append_at_index(std::variant<int, double, std::string, bool> item, size_t index) {
    if (index <= data.size() && index > 0) {
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

