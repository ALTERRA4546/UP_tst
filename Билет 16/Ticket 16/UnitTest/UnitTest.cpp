#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "C:\Users\King Night\Desktop\Тестирование билеты\Билет 16\Ticket 16\Ticket 16\Ticket 16.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest) {
public:

    TEST_METHOD(AddElementTest) {
        std::vector<int> collection;
        CollectionOperations::addElement(collection, 5);
        Assert::AreEqual((size_t)1, CollectionOperations::getSize(collection));
        Assert::IsTrue(CollectionOperations::containsElement(collection, 5));
    }

    TEST_METHOD(RemoveElementTest) {
        std::vector<int> collection;
        CollectionOperations::addElement(collection, 5);
        CollectionOperations::addElement(collection, 10);
        CollectionOperations::removeElement(collection, 5);
        Assert::AreEqual((size_t)1, CollectionOperations::getSize(collection));
        Assert::IsFalse(CollectionOperations::containsElement(collection, 5));
        Assert::IsTrue(CollectionOperations::containsElement(collection, 10));
    }

    TEST_METHOD(ContainsElementTest) {
        std::vector<int> collection;
        CollectionOperations::addElement(collection, 5);
        Assert::IsTrue(CollectionOperations::containsElement(collection, 5));
        Assert::IsFalse(CollectionOperations::containsElement(collection, 10));
    }

    TEST_METHOD(GetSizeTest) {
        std::vector<int> collection;
        CollectionOperations::addElement(collection, 5);
        CollectionOperations::addElement(collection, 10);
        Assert::AreEqual((size_t)2, CollectionOperations::getSize(collection));
    }

    TEST_METHOD(ClearCollectionTest) {
        std::vector<int> collection;
        CollectionOperations::addElement(collection, 5);
        CollectionOperations::clearCollection(collection);
        Assert::AreEqual((size_t)0, CollectionOperations::getSize(collection));
    }

    TEST_METHOD(RemoveNonExistingElementTest) {
        std::vector<int> collection;
        CollectionOperations::addElement(collection, 5);
        CollectionOperations::removeElement(collection, 10);
        Assert::AreEqual((size_t)1, CollectionOperations::getSize(collection));
        Assert::IsTrue(CollectionOperations::containsElement(collection, 5));
    }
    };
}
