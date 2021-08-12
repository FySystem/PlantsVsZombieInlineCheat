#pragma once
#include "dllmain.h"

namespace Offset
{
	constexpr DWORD Base = 0x6A9EC0;//基地址
	constexpr DWORD SunlightOffset1 = 0x768;//阳光偏移1
	constexpr DWORD SunlightOffset2 = 0x5560;//阳光偏移2

	constexpr DWORD UnCDAddress = 0x487296;//CD实现地址

	constexpr DWORD notStopAddress = 0x54EB80;//后台运行

	constexpr DWORD PlantsCD = 0x00464A96;//植物射速CD
	constexpr DWORD PlantsCD2 = 0x0045F8BF;//植物间隔CD

	constexpr DWORD PiranhaCD = 0x46324C;//食人花CD
}