#include <iostream>
#include "windows.h"
#include "thread"

class ProcessCreation {
public:
    // Создание процесса
    static bool createProcess(const std::string& commandLine);

    // Проверка, запущен ли процесс
    static bool isProcessRunning(HANDLE processHandle);

    // Закрытие дескриптора процесса
    static void closeProcessHandle(HANDLE processHandle);
};

bool ProcessCreation::createProcess(const std::string& commandLine) {
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    // Создание процесса
    if (!CreateProcessA(
        nullptr,  // Имя модуля (используем командную строку)
        const_cast<LPSTR>(commandLine.c_str()), // Командная строка
        nullptr,  // Аттрибуты процесса
        nullptr,  // Аттрибуты потока
        FALSE,    // Наследование дескрипторов
        0,        // Флаги создания
        nullptr,  // Окружение
        nullptr,  // Текущий каталог
        &si,       // STARTUPINFO
        &pi       // PROCESS_INFORMATION
    )) {
        return false;
    }

    // Закрываем дескрипторы после успешного создания процесса
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return true;
}

bool ProcessCreation::isProcessRunning(HANDLE processHandle) {
    if (processHandle == NULL) {
        return false; // Invalid handle
    }

    DWORD exitCode;
    if (GetExitCodeProcess(processHandle, &exitCode)) {
        return (exitCode == STILL_ACTIVE);
    }
    else {
        return false; // Error getting exit code
    }
}

void ProcessCreation::closeProcessHandle(HANDLE processHandle) {
    if (processHandle != NULL) {
        CloseHandle(processHandle);
    }
}

int main()
{
    std::cout << "Hello World!\n";
}