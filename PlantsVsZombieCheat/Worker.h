#pragma once
#include "Hacker.h"

class Worker
{
public:
	void init();

	void ShowMenu();

	void keyBoard();

	void Work();

	void ColorPrintf(const bool& state, const char* str) {
		if (state) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
			cout << str << endl;
		}
		else {
			cout << str << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);//设置颜色，没有添加颜色，故为原色
		cout << endl;
	}
private:
	bool bSunlight = false;
	bool bCD = false;
	bool bStop = false;
	bool bPlantsSpeedCd = false;
	bool bPiranhaCD = false;
};