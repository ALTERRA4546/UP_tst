#include <iostream>
#include <vector>

class CollectionOperations {
public:
    // Добавление элемента в коллекцию
    static void addElement(std::vector<int>& collection, int element) {
        collection.push_back(element);
    }

    // Удаление элемента из коллекции
    static void removeElement(std::vector<int>& collection, int element) {
        auto it = std::find(collection.begin(), collection.end(), element);
        if (it != collection.end()) {
            collection.erase(it);
        }
    }

    // Поиск элемента в коллекции
    static bool containsElement(const std::vector<int>& collection, int element) {
        return std::find(collection.begin(), collection.end(), element) != collection.end();
    }

    // Получение размера коллекции
    static size_t getSize(const std::vector<int>& collection) {
        return collection.size();
    }

    // Очистка коллекции
    static void clearCollection(std::vector<int>& collection) {
        collection.clear();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}