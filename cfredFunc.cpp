#include "cfred.h"

HDC initHDC(){
	return GetDC(NULL);
}

void initCheckPoints(CHECKPOINT checkPoint[], int checkPointNum) {
	int checkinXPosition = 950;
	int xOffset = 5;
	int checkinYPosition = 608;
	int yOffset = 0;
	for (int i = 0; i < checkPointNum; i++) {
		checkPoint[i].x = checkinXPosition + i * xOffset;
		checkPoint[i].y = checkinYPosition + i * yOffset;
	}
}

int checkinPoints(HDC hdc,CHECKPOINT checkPoint[], int checkPointNum) {
	int passedPoint = 0;

	for (int i = 0; i < checkPointNum; i++) {
		checkPoint[i].color = GetPixel(hdc,checkPoint[i].x, checkPoint[i].y);
		if (GetRValue(checkPoint[i].color) > 110 && GetGValue(checkPoint[i].color) < 80 && GetBValue(checkPoint[i].color) < 80){
			passedPoint++;
		}
	}
	return passedPoint;
}

bool isSniperRifle(HDC hdc) {
	COLORREF pointColor =GetPixel(hdc,2,2);
	if (pointColor == 0x000000) {
		return true;
	}
	else {
		return false;
	}
}