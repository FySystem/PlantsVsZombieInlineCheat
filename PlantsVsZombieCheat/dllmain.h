#pragma once
#include <Windows.h>
#include <iostream>

//程序入口
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);

//执行线程
DWORD WINAPI ThreadFunc(LPVOID);