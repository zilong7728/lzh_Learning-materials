/*****************学生成绩管理系统v1.1.10*****************
******************注意：系统人数上限为100*****************
****测试数据格式为“学生编号 语文成绩 数学成绩 英语成绩\n”****/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义学生结构体
 typedef struct studenttype
{
	int num = 0;//学生编号
	int ch = 0;//语文成绩
	int ma = 0;	//数学成绩
	int eng = 0;//英语成绩
	int sum = 0;//总成绩
	float ave = (float)sum / 3;	//该生三科平均分
}student;

//声明要使用的函数函数
void fun1(student stu[100], int stunum, int failnum);
void fun2(student stu[100], int stunum, int aboveave, float classave);
void fun3(student stu[100], int n);
void fun4(student stu[100], int n);
void fun5(student stu[100], int n, FILE *fp);
void fun6(student stu[100], int n);

//主函数
int main()
{
	//打开储存成绩信息的文件
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp,"/*TestData目录*/","a+");
	if (fp == NULL)
	{
		printf("No data");
		return -1;
	}

	//读入学生成绩
	int i = 0;
	student stu[100];
	while(!feof(fp))
	{
		fscanf_s(fp, "%d%d%d%d", &stu[i].num, &stu[i].ch, &stu[i].ma, &stu[i].eng);
		stu[i].sum = (stu[i].ch + stu[i].ma + stu[i].eng);//计算个人总分
		stu[i].ave = (float)stu[i].sum / 3;//计算个人平均分
		i++;
	}
	int stunum = i;

	//计算班级平均分、及格和不及格、成绩在平均分之上的人数
	float classave=0;
	int pass = 0, failnum = 0, aboveave = 0;
	for (int i = 0; i < stunum; i++)
	{
		classave += stu[i].ave;
	}
	classave = classave / stunum;
	for (int i = 0; i < stunum; i++)
	{
		if (stu[i].sum < 180)
		{
			failnum++;
		}
		if (stu[i].ave > classave)
		{
			aboveave++;
		}
	}

reStart://再次使用系统的入口

	//打印功能列表并选择要使用的功能
	printf("\t  ***功能列表***\n");
	printf("\t1 打印总成绩不及格的学生学号并统计人数\n");
	printf("\t2 统计成绩在全班平均分之上的学生数并打印名单\n");
	printf("\t3 统计各分数段的学生人数和百分比 \n"); 
	printf("\t4 按总分成绩从高到低排名\n");
	printf("\t5 打印出名次表\n");
	printf("\t6 查找学生成绩和排名\n");
	printf("\t  请输入要使用的功能序号：");
	int f;
	scanf_s("%d", &f);

	//选择要使用的函数
	switch (f)
	{
	case 1:fun1(stu, stunum, failnum);
		break;
	case 2:fun2(stu, stunum, aboveave, classave);
		break;
	case 3:fun3(stu, stunum);
		break;
	case 4:fun4(stu, stunum);
		break;
	case 5:fun5(stu, stunum, fp);
		break;
	case 6:fun6(stu, stunum);
		break;
	default:printf("错误！");
	}

reScan://再次询问是否结束程序的入口

	//询问是否结束使用
	printf("是否要结束程序？\n结束请按0，继续使用请按1\n");
	int x;
	scanf_s("%d", &x);
	if (x == 0) { goto end; }
	else if (x == 1) { goto reStart; }
	else { printf("错误！"); goto reScan; }

end://程序结束的出口

	fclose(fp);
	return 0;
}

//功能1：打印总成绩不及格的学生学号并统计人数函数
void fun1(student stu[100], int stunum, int failnum)
{
	printf("学号为：");
	for (int i = 0; i < stunum; i++)
	{
		if (stu[i].sum < 180)
		{
			printf("%d号 ", stu[i].num);
		}
	}
	printf("\n总人数为：%d\n", failnum);
}

//功能2：统计成绩在全班平均分之上的学生数并打印名单
void fun2(student stu[100], int stunum, int aboveave , float classave)
{
	printf("成绩在平均分之上的有：");
	for (int i = 0; i < stunum; i++)
	{
		if (stu[i].ave > classave)
		{
			printf("%d号 ", stu[i].num);
		}
	}
	printf("\n总人数为：%d\n", aboveave);
}

//功能3：统计各分数段人数和百分比并输出
void fun3(student stu[100], int n)
{
	int num50 = 0, num60 = 0, num70 = 0, num80 = 0, num90 = 0;
	float per50, per60, per70, per80, per90;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].sum < 180) { num50++; }
		else if (stu[i].sum < 210) { num60++; }
		else if (stu[i].sum < 240) { num70++; }
		else if (stu[i].sum < 270) { num80++; }
		else { num90++; }
	}
	per50 = (float)num50 / n;
	per60 = (float)num60 / n;
	per70 = (float)num70 / n;
	per80 = (float)num80 / n;
	per90 = (float)num90 / n;
	printf("60以下：%d 百分比：%f\n", num50, per50);
	printf("60~70：%d 百分比：%f\n", num60, per60);
	printf("70~80：%d 百分比：%f\n", num70, per70);
	printf("80~90：%d 百分比：%f\n", num80, per80);
	printf("90以上：%d 百分比：%f\n", num90, per90);
}

//功能4：按总分成绩从高到低排名
void fun4(student stu[100], int n)
{
	student tool;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stu[j].sum < stu[i].sum)
			{
				tool = stu[j];
				stu[j] = stu[i];
				stu[i] = tool;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		printf("第%d名：学号：%d,语文：%d，数学：%d，英语：%d，总分：%d\n", n - i,stu[i].num, stu[i].ch, stu[i].ma, stu[i].eng, stu[i].sum);
	}
}

//功能5：打印名次表
void fun5(student stu[100], int n, FILE *fp)
{
	student tool;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stu[j].sum < stu[i].sum)
			{
				tool = stu[j];
				stu[j] = stu[i];
				stu[i] = tool;
			}
		}
	}
	fprintf(fp, "\n名次  学号  语文  数学  英语  总分\n");
	for (int i = n - 1; i >= 0; i--)
	{
		fprintf(fp, " %d    %d    %d    %d    %d    %d\n", n - i, stu[i].num, stu[i].ch, stu[i].ma, stu[i].eng, stu[i].sum);
	}
}

//功能6：查找学生成绩和排名
void fun6(student stu[100],int n)
{
	student tool;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stu[j].sum < stu[i].sum)
			{
				tool = stu[j];
				stu[j] = stu[i];
				stu[i] = tool;
			}
		}
	}
	int num, i = 0;
	printf("请输入该生学号：");
	scanf_s("%d", &num);
	while (stu[i].num != num&&i<n)
	{
		i++;
	}
	if(i<n)
	printf("该生排名：%d,语文：%d,数学：%d,英语：%d,总分：%d", n - i, stu[i].ch, stu[i].ma, stu[i].eng, stu[i].sum);
}