#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
//请在VS2019中编译 其他的没测试过
//目前仅适用于1920*1080设置下的CF,如果要改变，需要修改各种数据
//这是红点检测的个数，用于初始化数组大小 和批量替换后边的各种常量，见后边
#define POINT_NUM 5
int main()
{
	//HDC是用于操作屏幕画面的东西，获取就完事了，不用懂的。我也不太懂
	HDC hdc = GetDC(NULL);
	//这是一个COLOREF类型的数组，COLOREF是个类似于0x66ccff这样的数（RGB）
	COLORREF got[POINT_NUM] ;

	int redPoint = 0;//检测名字的红点个数(表示每一个循环里检测到了几个红名的点，最多5个(上面define过))
	int bb = 608;//这是红名位于屏幕的高度
	while (1)//让循环起来，每个循环都计算有没有检测到红点
	{
		if (GetKeyState(VK_DECIMAL) < 0)
		{
			break;//这个是检测小键盘(.)键的输入，输入则跳出循环，以便把垃圾回收，直接关闭程序会导致内存泄漏
		}
		//第1个监测点。GetPixel用于检测屏幕上一个点的COLORREF值(rgb值) hdc是获取到的HDC型变量，填上就行，无需理解，
		//950是屏幕像素点位置(从左往右第950个像素点)
		//bb这是红名位于屏幕的高度（从上往下数第bb个像素点），我设置为了同一高度
		//GetRValue，GetGValue，GetBValue能把COLORREF类型的值分别转换为单独的R,G,B值（0~255)
		//printf可有可无，在写代码时用于检查是否正常运行，如果删去，运行速度会更快，但没有可见化的东西
		//SetPixel用于在屏幕上画一个点。我画在了950，bb-1上（如果画在bb上，那bb永远都是白色了，就无法检测了）
		//SetPixel也是为了可视化程序，可有可无。
		got[0] = GetPixel(hdc, 950, bb);
		//printf("%3d,%3d,%3d  ", GetRValue(got[0]), GetGValue(got[0]), GetBValue(got[0]));
		//SetPixel(hdc, 950, bb-1, RGB(255, 255, 255));
		//第2个监测点。
		got[1] = GetPixel(hdc, 955, bb);
		//printf("%3d,%3d,%3d  ", GetRValue(got[1]), GetGValue(got[1]), GetBValue(got[1]));
		//SetPixel(hdc, 955, bb-1, RGB(255, 255, 255));
		//第3个监测点。
		got[2] = GetPixel(hdc, 960, bb);
		//printf("%3d,%3d,%3d  ", GetRValue(got[2]), GetGValue(got[2]), GetBValue(got[2]));
		//SetPixel(hdc, 960, bb-1, RGB(255, 255, 255));
		//第4个监测点。
		got[3] = GetPixel(hdc, 965, bb);
		//printf("%3d,%3d,%3d  ", GetRValue(got[3]), GetGValue(got[3]), GetBValue(got[3]));
		//SetPixel(hdc, 965, bb - 1, RGB(255, 255, 255));
		//第5个监测点。
		got[4] = GetPixel(hdc, 970, bb);
		//printf("%3d,%3d,%3d\n", GetRValue(got[4]), GetGValue(got[4]), GetBValue(got[4]));
		//SetPixel(hdc, 970, bb - 1, RGB(255, 255, 255));

		for (int i = 0; i < POINT_NUM; i++)
		{
			//这是检查获取到的5个点的颜色。我试了很多次，那个红色很模糊，可调。这里用这个还可以，表示R>110,G<80,B<80的像素点
			if (GetRValue(got[i]) >110 && GetGValue(got[i]) < 80 && GetBValue(got[i]) < 80)
			{
				redPoint++;//找到的可行红点数++
			}
		}
		if (redPoint >=1)//这里也是可调的。只要检测到1个以上的可行红点就让他画出我的监视方块，后边单片机要看这片方块
		{
			Rectangle(hdc,0,980,100,1080);//画出一个举行。参数:(HDC hdc,x1,y1,x2,y2)   (x1,y1)是矩形左上角的点 另一个是右下角的点
			//这个矩形是被默认填充为白色的，白色比较好被单片机的光敏电阻检测到 位置是左下角，大小为100*100
		}
		redPoint = 0;//循环结束，让红色可行点为0，接着下一次循环
		Sleep(1);	//建议保留。
	}
		ReleaseDC(NULL,hdc);//这是按下小键盘.键后做的操作，将所有的东西释放掉，防止内存泄漏。也就是正常关闭程序了
}
