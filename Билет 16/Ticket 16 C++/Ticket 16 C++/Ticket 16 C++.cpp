#include <iostream>
#include <vector>
#include <algorithm>

class Collection {
private:
    std::vector<int> data;

public:
    Collection() {}

    void add(int element) {
        data.push_back(element);
    }

    int get(size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t size() const {
        return data.size();
    }

    void remove(size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        data.erase(data.begin() + index);
    }

    void clear() {
        data.clear();
    }
};

int main()
{

}