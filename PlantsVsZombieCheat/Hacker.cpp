#include "Hacker.h"
#include "Offset.hpp"

//HooKJmpBack
DWORD JmpBack = 0x54eb87; //��̨������ת��ȥ��ַ

//��ȫ�ɻ��ִ��inlineHook����
__declspec(naked) void Background_runHook() {
	_asm {
		or byte ptr[esi + 0x000004CE], 0x01
		jmp JmpBack
	}
}

Hacker::Hacker()
{
	//--------��CD��ʼ��-----------
	ReadProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::UnCDAddress),
		m_OldUnlimitedCDAddress,
		sizeof(m_OldUnlimitedCDAddress), nullptr);
	m_NewUnlimitedCDAddress[0] = '\x90';
	m_NewUnlimitedCDAddress[1] = '\x90';
	//----------------------------

	//--------��̨���г�ʼ��-----------
	ReadProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::notStopAddress),
		m_Old_Background_run_Address,
		sizeof(m_Old_Background_run_Address), nullptr);
	m_New_Background_run_Address[0] = '\xE9';
	*(DWORD*)(m_New_Background_run_Address + 1) = (DWORD)Background_runHook - (DWORD)Offset::notStopAddress - 5;
	m_New_Background_run_Address[5] = '\x90';
	m_New_Background_run_Address[6] = '\x90';
	//----------------------------

	//--------ֲ������CD��ʼ��-----------
	ReadProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PlantsCD),
		m_OldPlantsCD_Address, 
		sizeof(m_OldPlantsCD_Address), nullptr);
	for (int i = 0; i < 6; i++) {
		m_NewPlantsCD_Address[i] = '\x90';
	}
	ReadProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PlantsCD2),
		m_OldPlantsCD2_Address,
		sizeof(m_OldPlantsCD2_Address), nullptr);
	m_NewPlantsCD2_Address[0] = '\xB9';
	m_NewPlantsCD2_Address[1] = '\x22';
	m_NewPlantsCD2_Address[2] = '\x00';
	m_NewPlantsCD2_Address[3] = '\x00';
	m_NewPlantsCD2_Address[4] = '\x00';
	//----------------------------

	ReadProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PiranhaCD),
		m_OldPiranhaCD_Address,
		sizeof(m_OldPiranhaCD_Address), nullptr);
	m_NewPiranhaCD_Address[0] = '\x31';
	m_NewPiranhaCD_Address[1] = '\xC0';
	m_NewPiranhaCD_Address[2] = '\x90';
}

//ʵ����������
void Hacker::unlimitedSunlight()
{
	DWORD tempBase = 0;
	memcpy(&tempBase, (DWORD*)(Offset::Base), sizeof(tempBase));
	if (tempBase != 0) {
		DWORD temp = 0;
		memcpy(&temp, (DWORD*)(tempBase + Offset::SunlightOffset1), sizeof(temp));
		if (temp != 0) {
			memcpy((DWORD*)(temp + Offset::SunlightOffset2), &m_MaxSunlight, sizeof(m_MaxSunlight));
		}
	}
}

//--------ʵ������CD-----------
BOOL Hacker::EnableUnlimitedCD()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::UnCDAddress),
		m_NewUnlimitedCDAddress,
		sizeof(m_NewUnlimitedCDAddress), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
BOOL Hacker::DisableUnlimitedCD()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::UnCDAddress),
		m_OldUnlimitedCDAddress,
		sizeof(m_OldUnlimitedCDAddress), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
//----------------------------


//--------ʵ�ֺ�̨����-----------
BOOL Hacker::EnableBackground_run()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::notStopAddress),
		m_New_Background_run_Address,
		sizeof(m_New_Background_run_Address), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
BOOL Hacker::DisableBackground_run()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::notStopAddress),
		m_Old_Background_run_Address,
		sizeof(m_Old_Background_run_Address), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
//------------------------------


//--------ʵ��ֲ������CD-----------
BOOL Hacker::EnablePlantsCD()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PlantsCD),
		m_NewPlantsCD_Address, 6, nullptr)) {
		return TRUE;
	}
	return FALSE;
}
BOOL Hacker::DisablePlantsCD()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PlantsCD),
		m_OldPlantsCD_Address,
		6, nullptr)) {
		return TRUE;
	}
	return FALSE;
}
BOOL Hacker::EnablePlantsCD2()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PlantsCD2),
		m_NewPlantsCD2_Address, 
		sizeof(m_NewPlantsCD2_Address), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
BOOL Hacker::DisablePlantsCD2()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PlantsCD2),
		m_OldPlantsCD2_Address,
		sizeof(m_OldPlantsCD2_Address), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
//------------------------------


//--------ʳ�˻���CD-----------
BOOL Hacker::EnablePiranhaCD()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PiranhaCD),
		m_NewPiranhaCD_Address,
		sizeof(m_NewPiranhaCD_Address), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
BOOL Hacker::DisblePiranhaCD()
{
	if (WriteProcessMemory(GetCurrentProcess(),
		LPVOID(Offset::PiranhaCD),
		m_OldPiranhaCD_Address,
		sizeof(m_OldPiranhaCD_Address), nullptr)) {
		return TRUE;
	}
	return FALSE;
}
//------------------------------