/*Ä£ÄâÊ±ÖÓ */ 
#include<stdio.h>
#include<windows.h>
typedef struct clock
{
	int hour;
	int minute;
	int second;
}CLOCK;

int main()
{
	CLOCK t={0,0,0};
	int n=100,i=0;
	char c;
	while(++i<n)
	{
		t.second++;
		if(t.second>=60)
		{
			t.second=0;
			t.minute++;
		}
		if(t.minute>=60)
		{
			t.minute=0;
			t.hour++;
		}
		if(t.hour>=24)
		{
			t.hour=0;
		}
		printf("%d:%d:%d\r",t.hour,t.minute,t.second);
		Sleep(1000);
	} 
	
	
}
