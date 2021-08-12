#pragma once
#include "dllmain.h"
using namespace std;

class Hacker
{
public:
	Hacker();

	//无限阳光
	void unlimitedSunlight();

	//无限CD
	BOOL EnableUnlimitedCD();
	BOOL DisableUnlimitedCD();

	//后台运行
	BOOL EnableBackground_run();
	BOOL DisableBackground_run();

	//植物射速CD
	BOOL EnablePlantsCD();
	BOOL DisablePlantsCD();
	BOOL EnablePlantsCD2();
	BOOL DisablePlantsCD2();

	//食人花无CD
	BOOL EnablePiranhaCD();
	BOOL DisblePiranhaCD();

private:
	int m_MaxSunlight = 9999;

	BYTE m_NewUnlimitedCDAddress[2];
	BYTE m_OldUnlimitedCDAddress[2];

	BYTE m_New_Background_run_Address[7];
	BYTE m_Old_Background_run_Address[7];

	BYTE m_NewPlantsCD_Address[6];
	BYTE m_OldPlantsCD_Address[6];

	BYTE m_NewPlantsCD2_Address[5];
	BYTE m_OldPlantsCD2_Address[5];

	BYTE m_NewPiranhaCD_Address[3];
	BYTE m_OldPiranhaCD_Address[3];
};