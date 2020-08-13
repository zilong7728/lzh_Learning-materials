#include<stdio.h>
#include<string.h>
typedef struct student{
	char name[30];
	int chinese;
	int math;
	int eng;
}student;
int convert(char* original)
{
	int result=0;
	for(int i=0;i<strlen(original);i++)
	{
		result=result*10+original[i]-48;
	}
	return result;
}
int main()
{
	FILE *fp = NULL;
	fp = fopen("data_in.txt", "r");
	int counter=0;
	char cache[265];
	while(!feof(fp))
	{
		fgets(cache,255,fp);
		counter++; 
	}
	int stdnumber=counter/4;
	student class1[stdnumber];
	fclose(fp);
	fp = fopen("data_in.txt", "r");
	for(counter=0;counter<stdnumber*4;counter+=4)
	{
		fgets(class1[counter/4].name,255,fp);
		fgets(cache,255,fp);
		cache[strlen(cache)-1]='\0';
		class1[counter/4].chinese=convert(cache);
		fgets(cache,255,fp);
		cache[strlen(cache)-1]='\0';
		class1[counter/4].math=convert(cache);
		fgets(cache,255,fp);
		cache[strlen(cache)-1]='\0';
		class1[counter/4].eng=convert(cache);
		printf("name:%s",class1[counter/4].name);
		printf("chinese:%d\n",class1[counter/4].chinese);
		printf("math:%d\n",class1[counter/4].math);
		printf("english:%d\n\n",class1[counter/4].eng);
	}
} 
