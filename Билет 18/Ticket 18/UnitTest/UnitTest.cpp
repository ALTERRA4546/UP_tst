#include "pch.h"
#include "CppUnitTest.h"
#include "vector"
#include "C:\Users\King Night\Desktop\Тестирование билеты\Билет 18\Ticket 18\Ticket 18\Ticket 18.cpp"
#include <cmath>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1_NoRealRoots)
		{
			vector<double> result = Equation::solve(1, 1, 1);

			Assert::IsTrue(result.empty());
		}

		TEST_METHOD(TestMethod2_OneRealRoot)
		{
			vector<double> result = Equation::solve(1, 2, 1);

			Assert::AreEqual((size_t)1, result.size());

			Assert::AreEqual(-1.0, result[0], 0.0001);
		}

		TEST_METHOD(TestMethod3_TwoRealRoots)
		{
			vector<double> result = Equation::solve(1, -5, 6);

			Assert::AreEqual((size_t)2, result.size());

			//sort(result.begin(), result.end());

			Assert::AreEqual(2.0, result[0], 0.0001);
			Assert::AreEqual(3.0, result[1], 0.0001);
		}

		TEST_METHOD(TestMethod4_InvalidInputAIsZero)
		{
			try
			{
				Equation::solve(0, 2, 3);
				Assert::Fail(L"Expected an exception to be thrown.");
			}
			catch (const std::invalid_argument& e)
			{
				Assert::AreEqual("Coefficient 'a' cannot be zero in a quadratic equation.", e.what());
			}
			catch (...)
			{
				Assert::Fail(L"Unexpected exception type thrown.");
			}
		}
	};
}
