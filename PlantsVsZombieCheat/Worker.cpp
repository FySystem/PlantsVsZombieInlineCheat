#include "Worker.h"
using namespace std;

void Worker::init()
{
	AllocConsole();
	SetConsoleTitleA("QQ:2783538268");
	freopen("CON", "w", stdout);
}

void Worker::ShowMenu()
{
	ColorPrintf(bSunlight, "[F1]\t无限阳光");
	ColorPrintf(bCD, "[F2]\t无限CD");
	ColorPrintf(bStop, "[F3]\t后台运行");
	ColorPrintf(bPlantsSpeedCd, "[F4]\t植物快速射击(有概率导致游戏崩溃)");
	ColorPrintf(bPiranhaCD, "[F5]\t食人花无CD");
	Sleep(80);
	system("cls");
}

void Worker::keyBoard()
{
	if (GetAsyncKeyState(VK_F1)) {
		bSunlight = !bSunlight;
	}
	if (GetAsyncKeyState(VK_F2)) {
		bCD = !bCD;
	}
	if (GetAsyncKeyState(VK_F3)) {
		bStop = !bStop;
	}
	if (GetAsyncKeyState(VK_F4)) {
		bPlantsSpeedCd = !bPlantsSpeedCd;
	}
	if (GetAsyncKeyState(VK_F5)) {
		bPiranhaCD = !bPiranhaCD;
	}
}

void Worker::Work()
{
	shared_ptr<Hacker> hack(new Hacker);

	while (true)
	{
		ShowMenu();
		keyBoard();
		//无限阳光
		if (bSunlight) {
			hack->unlimitedSunlight();
		}

		//无CD
		if (bCD) {
			hack->EnableUnlimitedCD();
		}
		else {
			hack->DisableUnlimitedCD();
		}

		//后台运行
		if (bStop) {
			hack->EnableBackground_run();
		}
		else {
			hack->DisableBackground_run();
		}

		//植物攻击无CD
		if (bPlantsSpeedCd) {
			hack->EnablePlantsCD();
			hack->EnablePlantsCD2();
		}
		else {
			hack->DisablePlantsCD();
			hack->DisablePlantsCD2();
		}
		
		//食人花CD
		if (bPiranhaCD) {
			hack->EnablePiranhaCD();
		}
		else {
			hack->DisblePiranhaCD();
		}
	}
}