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
	ColorPrintf(bSunlight, "[F1]\t��������");
	ColorPrintf(bCD, "[F2]\t����CD");
	ColorPrintf(bStop, "[F3]\t��̨����");
	ColorPrintf(bPlantsSpeedCd, "[F4]\tֲ��������(�и��ʵ�����Ϸ����)");
	ColorPrintf(bPiranhaCD, "[F5]\tʳ�˻���CD");
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
		//��������
		if (bSunlight) {
			hack->unlimitedSunlight();
		}

		//��CD
		if (bCD) {
			hack->EnableUnlimitedCD();
		}
		else {
			hack->DisableUnlimitedCD();
		}

		//��̨����
		if (bStop) {
			hack->EnableBackground_run();
		}
		else {
			hack->DisableBackground_run();
		}

		//ֲ�﹥����CD
		if (bPlantsSpeedCd) {
			hack->EnablePlantsCD();
			hack->EnablePlantsCD2();
		}
		else {
			hack->DisablePlantsCD();
			hack->DisablePlantsCD2();
		}
		
		//ʳ�˻�CD
		if (bPiranhaCD) {
			hack->EnablePiranhaCD();
		}
		else {
			hack->DisblePiranhaCD();
		}
	}
}