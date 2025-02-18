#include "pch.h"
#include "CppUnitTest.h"
#include "string"
#include "C:\Users\King Night\Desktop\Тестирование билеты\Билет 17\Ticket 17\Ticket 17\Ticket 17.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
    TEST_CLASS(ProcessCreationTests) {
public:
    TEST_METHOD(CreateProcess_ValidCommand) {

        string commandLine = "notepad.exe";

        bool result = ProcessCreation::createProcess(commandLine);

        Assert::IsTrue(result);
    }

    TEST_METHOD(CreateProcess_InvalidCommand) {
        string commandLine = "nonexistent_program.exe";

        bool result = ProcessCreation::createProcess(commandLine);

        Assert::IsFalse(result);
    }

    TEST_METHOD(IsProcessRunning_RunningProcess) {
        string commandLine = "notepad.exe";

        STARTUPINFOA si = { sizeof(si) };
        PROCESS_INFORMATION pi;

        if (!CreateProcessA(
            nullptr,
            const_cast<LPSTR>(commandLine.c_str()),
            nullptr,
            nullptr,
            FALSE,
            0,
            nullptr,
            nullptr,
            &si,
            &pi
        )) {
            Assert::Fail();
        }

        this_thread::sleep_for(std::chrono::milliseconds(500));

        bool isRunning = ProcessCreation::isProcessRunning(pi.hProcess);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        Assert::IsTrue(isRunning);
    }

    TEST_METHOD(IsProcessRunning_ClosedProcess) {
        string commandLine = "cmd.exe /c exit";

        STARTUPINFOA si = { sizeof(si) };
        PROCESS_INFORMATION pi;

        if (!CreateProcessA(
            nullptr,
            const_cast<LPSTR>(commandLine.c_str()),
            nullptr,
            nullptr,
            FALSE,
            0,
            nullptr,
            nullptr,
            &si,
            &pi
        )) {
            Assert::Fail();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));


        bool isRunning = ProcessCreation::isProcessRunning(pi.hProcess);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        Assert::IsFalse(isRunning);
    }
    };
}
