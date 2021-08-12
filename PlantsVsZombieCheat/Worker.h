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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
			cout << str << endl;
		}
		else {
			cout << str << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);//������ɫ��û�������ɫ����Ϊԭɫ
		cout << endl;
	}
private:
	bool bSunlight = false;
	bool bCD = false;
	bool bStop = false;
	bool bPlantsSpeedCd = false;
	bool bPiranhaCD = false;
};