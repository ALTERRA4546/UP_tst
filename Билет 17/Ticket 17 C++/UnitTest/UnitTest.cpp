#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\King Night\Desktop\Тестирование билеты\Билет 16\Ticket 17 C++\Ticket 17 C++\Ticket 17 C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(ProcessLauncherTests)
	{
	public:

		TEST_METHOD(LaunchProcess_ValidExecutable_ReturnsSuccess)
		{
			std::wstring executablePath = L"C:\\Windows\\System32\\notepad.exe";
			std::wstring arguments = L"";

			int result = LaunchProcess(executablePath, arguments);

			Assert::AreEqual(0, result, L"LaunchProcess should return 0 for a valid executable.");
		}

		TEST_METHOD(LaunchProcess_InvalidExecutable_ReturnsErrorCode)
		{
			std::wstring executablePath = L"C:\\InvalidPath\\NonExistent.exe";
			std::wstring arguments = L"";
			int result = LaunchProcess(executablePath, arguments);

			Assert::AreNotEqual(0, result, L"LaunchProcess should return a non-zero error code for an invalid executable.");

			Assert::AreEqual((int)ERROR_FILE_NOT_FOUND, result, L"LaunchProcess should return ERROR_FILE_NOT_FOUND.");
		}


		TEST_METHOD(LaunchProcess_WithArguments_ReturnsSuccess)
		{
			std::wstring executablePath = L"C:\\Windows\\System32\\notepad.exe";
			std::wstring arguments = L"test.txt";


			int result = LaunchProcess(executablePath, arguments);


			Assert::AreEqual(0, result, L"LaunchProcess should return 0 when launching with arguments.");
		}

		TEST_METHOD(LaunchProcess_MemoryAllocationFailure_ReturnsErrorCode) {
			std::wstring longString(100000, 'A');
			std::wstring executablePath = longString;
			std::wstring arguments = L"";

			int result = LaunchProcess(executablePath, arguments);

			Assert::AreNotEqual(0, result, L"LaunchProcess should fail due to memory allocation");
		}
	};
}
