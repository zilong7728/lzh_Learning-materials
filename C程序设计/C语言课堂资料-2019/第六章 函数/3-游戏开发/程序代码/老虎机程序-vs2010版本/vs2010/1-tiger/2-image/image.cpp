#include"acllib.h"

const int mWidth=640,mHeight=480;
ACL_Image img;
const int width=100,height=100;
void TimerEvnet(int id);
int x=0,y=10;
int dx=5,dy=0;
void paint();
int Setup()
{
	int i,j;
	initWindow("imag",0,0,mWidth,mHeight);
	loadImage("1-bird.jpg",&img);
	paint();
	registerTimerEvent(TimerEvnet);
	startTimer(0,50);
	return 0;
}
void TimerEvnet(int id)
{
	switch(id)
	{
	case 0:
		x+=dx;
		if(x>mWidth-width || x<0)dx*=-1;
		break;
	default:
		break;
	}
	paint();
}
void paint()
{
	beginPaint();
	clearDevice();
	putImageScale(&img,x,y,width,height);
	
	endPaint();
}