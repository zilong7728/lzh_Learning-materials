#include<stdio.h>
#include<time.h>
#include<Windows.h>

int main() {
	/*
	法一：
	time_t t;
	char buff[26];
	for (;;) {
		t = time(&t);
		ctime_s(buff, sizeof buff, &t);
		printf("%s", buff);
		Sleep(1000);
		system("cls");
	}*/
	/*法二*/
	time_t now;
	struct tm local;
	for (;;) {
		time(&now);
		localtime_s(&local, &now);
		printf("%d:%d:%d", local.tm_hour, local.tm_min, local.tm_sec);
		Sleep(1000);
		system("cls");
	}
	return 0;
}