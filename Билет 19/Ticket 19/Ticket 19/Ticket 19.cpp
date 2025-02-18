#include <iostream>
#include "fstream"
#include "vector"

class ReadAndWrite {
public:
    bool writeToFile(const std::string& filename, const std::string& content) {
        std::ofstream outFile(filename);
        if (!outFile) {
            return false;
        }
        outFile << content;
        outFile.close();
        return true;
    }

    std::string readFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            return "";
        }
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();
        return content;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}