#include <iostream>
#include "process.h"
#include "windows.h"

int LaunchProcess(const std::wstring& executablePath, const std::wstring& arguments) {
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    std::wstring commandLine = executablePath + L" " + arguments;
    LPWSTR commandLineBuffer = _wcsdup(commandLine.c_str());

    if (commandLineBuffer == nullptr) {
        return -1;
    }

    BOOL result = CreateProcessW(
        nullptr,  
        commandLineBuffer,  
        nullptr,        
        nullptr,        
        FALSE,      
        0,           
        nullptr,       
        nullptr,       
        &si,           
        &pi    
    );

    free(commandLineBuffer);

    if (!result) {
        DWORD error = GetLastError();
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return error;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

int main()
{

}