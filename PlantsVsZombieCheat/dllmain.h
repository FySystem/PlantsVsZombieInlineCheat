#pragma once
#include <Windows.h>
#include <iostream>

//�������
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);

//ִ���߳�
DWORD WINAPI ThreadFunc(LPVOID);