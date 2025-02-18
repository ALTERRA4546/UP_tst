#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "C:\Users\King Night\Desktop\Тестирование билеты\Билет 16\Ticket 16 C++\Ticket 16 C++\Ticket 16 C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(AddAndSizeTest)
		{
			Collection c;
			Assert::AreEqual((size_t)0, c.size(), L"Initial size should be 0");

			c.add(10);
			Assert::AreEqual((size_t)1, c.size(), L"Size should be 1 after adding one element");

			c.add(20);
			Assert::AreEqual((size_t)2, c.size(), L"Size should be 2 after adding another element");
		}

		TEST_METHOD(GetTest)
		{
			Collection c;
			c.add(5);
			c.add(15);

			Assert::AreEqual(5, c.get(0), L"Element at index 0 should be 5");
			Assert::AreEqual(15, c.get(1), L"Element at index 1 should be 15");

			try {
				c.get(2);
				Assert::Fail(L"Expected std::out_of_range to be thrown");
			}
			catch (const std::out_of_range& e) {
			}
			catch (...) {
				Assert::Fail(L"Unexpected exception type thrown");
			}
		}

		TEST_METHOD(RemoveTest)
		{
			Collection c;
			c.add(1);
			c.add(2);
			c.add(3);

			c.remove(1);
			Assert::AreEqual((size_t)2, c.size(), L"Size should be 2 after removing one element");
			Assert::AreEqual(1, c.get(0), L"Element at index 0 should be 1");
			Assert::AreEqual(3, c.get(1), L"Element at index 1 should be 3");
		}

		TEST_METHOD(ClearTest)
		{
			Collection c;
			c.add(1);
			c.add(2);

			c.clear();
			Assert::AreEqual((size_t)0, c.size(), L"Size should be 0 after clearing the collection");
		}
	};
}
