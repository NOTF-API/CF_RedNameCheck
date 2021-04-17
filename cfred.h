#pragma once
#include <stdio.h>
#include <windows.h>
#include <graphics.h>

typedef struct {
	COLORREF color;
	short x;
	short y;
}CHECKPOINT;

/*
初始化屏幕的扫描器
*/
HDC initHDC();

/*
初始化红点
checkPoint[]:待初始化的CHECKPOINT类型的数组
checkPointNum:待初始化的检测个数
*/
void initCheckPoints(CHECKPOINT checkPoint[],int checkPointNum);

/*
	狙击枪开镜
	fireDelay:开镜延迟
	mouseDownTime:鼠标按下之后的等待时间
	afterdelay:做完这些操作后的等待时间
*/
void openScope(int fireDelay, int mouseDownTime, int afterDelay);

/*
	普通枪械的开火
	fireDelay:开枪延迟
	mouseDownTime:鼠标按下之后的等待时间
	afterdelay:做完这些操作后的等待时间
*/
void fire(int fireDelay, int mouseDownTime, int afterDelay);

/*
	狙击枪开枪并切枪开镜
	int fireDelay:开枪延迟
	int downTime,按下左键后的等待时间
	int afterFireDelayTime,松开左键后的等待时间,
	int afterRollUpTime,滚轮上滚后的等待时间,
	int afterRollDownTime滚轮下滚后的等待时间，同时也是切枪后的开镜等待时间
	int afterDelay,做完这些操作后的等待时间
*/
void fireAndSwitchGun(
	//开枪延迟
	int fireDelay,
	//按下左键后的等待时间
	int downTime,
	//松开左键后的等待时间
	int afterFireDelayTime,
	//滚轮上滚后的等待时间
	int afterRollUpTime,
	//做完这些操作后的等待时间
	int afterDelay
);

/*
检测检查点的情况
返回通过检验的个数
*/
int checkinPoints(HDC hdc, CHECKPOINT checkPoint[], int checkPointNum);

/*
检查当前是否为狙击枪的开镜状态
*/
bool isSniperRifle(HDC hdc);
