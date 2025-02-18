#include "pch.h"
#include "fstream"
#include "CppUnitTest.h"
#include "C:\Users\King Night\Desktop\Тестирование билеты\Билет 19\Ticket 19\Ticket 19\Ticket 19.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestWriteToFile)
        {
            ReadAndWrite rw;
            std::string filename = "testfile.txt";
            std::string content = "Hello, world!";

            bool result = rw.writeToFile(filename, content);
            Assert::IsTrue(result);

            std::ifstream inFile(filename);
            Assert::IsTrue(inFile.is_open());

            std::string readContent((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
            inFile.close();
            Assert::AreEqual(content, readContent);

            std::remove(filename.c_str());
        }

        TEST_METHOD(TestReadFromFile)
        {
            ReadAndWrite rw;
            std::string filename = "testfile.txt";
            std::string content = "Hello, world!";

            std::ofstream outFile(filename);
            outFile << content;
            outFile.close();

            std::string result = rw.readFromFile(filename);
            Assert::AreEqual(content, result);

            std::remove(filename.c_str());
        }

        TEST_METHOD(TestReadFromNonExistentFile)
        {
            ReadAndWrite rw;
            std::string filename = "nonexistentfile.txt";

            std::string result = rw.readFromFile(filename);
            Assert::IsTrue(result.empty());
        }
    };
}
