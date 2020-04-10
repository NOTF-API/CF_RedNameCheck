//#include <Mouse.h>
void setup() {//初始化部分
  pinMode(A0,OUTPUT);//设置A0口为输出口，输出鼠标信号
  pinMode(A1,INPUT);//设置A1口为输入口。读取鼠标信号
 // Mouse.begin();//开始模拟鼠标。
 digitalWrite(A0, HIGH);//把A0设置为低电平
}
int jc=0;
void loop() {//循环部分
//<680 WHITE
    jc=analogRead(A1);//jc是读取到的光敏电阻的电压//根据您的光敏电阻自行调节
  if (jc<=800) {
        //Mouse.press(MOUSE_LEFT);
        delay(15);//人的反应时间，50ms
        digitalWrite(A0,LOW);//相当于按下鼠标左键
        delay(30);//等一下
        digitalWrite(A0,HIGH);//松开鼠标左键
        delay(500);
        //Mouse.release(MOUSE_LEFT); 
    }
}
