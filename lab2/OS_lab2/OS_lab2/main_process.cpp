#include <iostream> 
#include <Windows.h>

using namespace std;

const int ciNumber = 8;


int main(int argc, char** argv)
{
    STARTUPINFO StartupInfo[ciNumber] = { NULL };
    PROCESS_INFORMATION ProcessInfo[ciNumber] = { NULL };
    int bListofProcess[ciNumber];
    DWORD dTimeSpend = NULL;

    for (int i(0); i < ciNumber; ++i)
    {
        StartupInfo[i].cb = sizeof(StartupInfo);
      bListofProcess[i] =  CreateProcess(
                                            NULL,
                                            "C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\teylor_raw\\Debug\\teylor_raw.exe -0.5 0.5 0.01 0.1",
                                            NULL,
                                            NULL,
                                            TRUE,
                                            NORMAL_PRIORITY_CLASS | CREATE_NO_WINDOW,
                                            NULL,
                                            NULL,
                                            &StartupInfo[i],
                                            &ProcessInfo[i]);
    }

    for (int i(0); i < ciNumber; ++i)
    {
       if (!bListofProcess[i]) { cout << i << "process is failed." << endl; }
       else
       {
            bListofProcess[i] = WaitForSingleObject(ProcessInfo[i].hProcess, INFINITE);
            GetExitCodeProcess(ProcessInfo[i].hProcess, &dTimeSpend);
            cout << "Time needed to count for " << i << " process is: " << dTimeSpend << " milisec"<<endl;
      }
    }


    for (int i(0); i < ciNumber; ++i)
    {
        CloseHandle(ProcessInfo[i].hProcess);
        CloseHandle(ProcessInfo[i].hThread);
    }


    system("pause");
    return 0;
}