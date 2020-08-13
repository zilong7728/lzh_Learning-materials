#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int id;
	char name[20];
	float chinese;
	float english;
	float math;

}student;
int main()
{
	FILE *fp;
	student stu[20];
	int i = 0,j=0;
	fopen_s(&fp, "stuScores.txt", "r");
	//fp = fopen("stuScores.txt", "r");
	if (fp == NULL)return -1;
	while (!feof(fp))
	{
		fscanf_s(fp, "%d %s %f %f %f", &stu[i].id, stu[i].name, 19,  &stu[i].chinese, &stu[i].english, &stu[i].math);
		++i;
	}
	for (j = 0;j < i;++j)
	{
		printf("%d %s %.2f %.2f %.2f\n",  stu[j].id, stu[j].name, stu[j].chinese, stu[j].english, stu[j].math);
	}
	system("pause");
	return 0;
}