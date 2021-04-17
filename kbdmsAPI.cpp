#include "cfred.h"

void fire(int fireDelay, int mouseDownTime,int afterDelay) {
	Sleep(fireDelay);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//按下鼠标左键
	Sleep(mouseDownTime);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开鼠标左键
	Sleep(afterDelay);
}

void openScope(int fireDelay, int mouseDownTime, int afterDelay) {
	Sleep(fireDelay);
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);//按下鼠标左键
	Sleep(mouseDownTime);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);//松开鼠标左键
	Sleep(afterDelay);
}

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
){
	Sleep(fireDelay);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//按下鼠标左键
	Sleep(downTime);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开鼠标左键
	Sleep(afterFireDelayTime);
	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 120, 0);//鼠标滚轮上滚
	Sleep(afterRollUpTime);
	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -120, 0);//鼠标滚轮上滚
	Sleep(afterDelay);
}

