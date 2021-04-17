#include "cfred.h"

void show(HDC hdc, CHECKPOINT checkPoint[], int checkPointNum);

int main() {
	int mode = 1;
	HDC hdc = initHDC();
	const int checkPointNum = 5;
	CHECKPOINT checkPoint[checkPointNum];
	initCheckPoints(checkPoint, checkPointNum);
	printf("已开始扫描红名,请自行修改游戏分辨率为1920*1080\n\
	本程序有制裁风险，请谨慎使用\
	按小键盘“+”键切换模式\n按数字.键终止程序\n");
	while (true){
		if (GetKeyState(VK_DECIMAL) < 0)break;
		if (GetKeyState(VK_ADD) < 0) {
			mode += 1;
			if (mode >2)mode = 1;
			switch (mode) {
			case 1:printf("当前:普通(步枪)模式\n"); break;
			case 2:printf("当前:自动切枪(狙击枪)模式\n"); break;
			}
			Sleep(100);
		}
		//checkin
		if (mode == 1) {
			int passedPoint = checkinPoints(hdc, checkPoint, checkPointNum);
			//fire
			if (passedPoint >= 1) {
				if (isSniperRifle(hdc) == true) {
					fireAndSwitchGun(1, 10, 100, 300,1000);
				}
				else {
					fire(1, 10, 150);
				}
			}
			//show(hdc,checkPoint,checkPointNum);
		}
		else if (mode == 2) {
			int passedPoint = checkinPoints(hdc, checkPoint, checkPointNum);
			//fire
			if (passedPoint >= 1) {
				if (isSniperRifle(hdc) == true) {
					fireAndSwitchGun(1, 10, 100, 300,1000);
				}
				else {
					openScope(1, 1, 1);
					fireAndSwitchGun(1, 10, 100, 300,1000);
				}
			}
			//show(hdc,checkPoint,checkPointNum);
		}	
	}
	return 0;
}

//test
void show(HDC hdc,CHECKPOINT checkPoint[],int checkPointNum) {
	for (int i = 0; i < checkPointNum; i++) {
		SetPixel(hdc, checkPoint[i].x, checkPoint[i].y + 1, 0xffffff);
	}
}