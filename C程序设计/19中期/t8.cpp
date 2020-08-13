#include<stdio.h>
#include<stdlib.h>

//定义“学生”结构 
struct student
{
	int no;
	int grade;
};

int main()
{
	struct student stu[10],tmp;
	
	//输入学生学号和成绩 
	for(int i=0;i<=9;i++)
	{
		scanf("%d %d",&stu[i].no,&stu[i].grade);
	}
	
	//对成绩排序 
	int max;
	for(int i=0;i<10;++i)
	{
		max=i;
		for(int j=i+1;j<10;++j)
		{
			if(stu[j].grade>stu[max].grade)
			{
				max=j;
			}
			tmp=stu[i];
			stu[i]=stu[max];
			stu[max]=tmp;
		}
	}
	
	/*输出最高分和最低分及对应学号*/
	
	//最高分 
	printf("最高分的有\n");
	for(int i=9;stu[i].grade==stu[9].grade;i--)
	{
		printf("%d\n",stu[i].no);
	} 
	printf("最高分为%d\n",stu[9].grade);
	
	//最低分
	printf("最低分的有\n");
	for(int i=0;stu[i].grade==stu[0].grade;i++)
	{
		printf("%d\n",stu[i].no);
	} 
	printf("最低分为%d\n",stu[0].grade);
	
	return 0;
}
