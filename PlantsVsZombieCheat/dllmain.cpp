#include "dllmain.h"
#include "Worker.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {

    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, ThreadFunc, 0, 0, 0);
        break;
    case DLL_PROCESS_DETACH:

        break;
    }
    return TRUE;
}

DWORD __stdcall ThreadFunc(LPVOID)
{
    shared_ptr<Worker> work(new Worker);
    work->init();
    
    work->Work();

    return 0;
}