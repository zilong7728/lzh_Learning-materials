/*输入单词译成密码，密码规律是：用原来的字母后面的第4个字母代替原来的字母。
例如，字母'A'后面第4个字母是"E",用"E"代替"A"，"Z"用"D"代替。例如，输入"China"应译为"Glmre"。
请编一程序，将输入单词译为密码后输出。
（回车结束单词输入；单词最长20，之后截断;输入单词长度为0或者输入不为字母，输出error)*/
#include<stdio.h>
#include<string.h>
int main()
{
    int i,a;
	char s[21],c[21];
	scanf("%s",s,21);
	for(i=0;(s[i]!='\0')&&(i<21);i++)
	{
		if(s[i]<65||(s[i]>90&&s[i]<97)||s[i]>122)
		{
			printf("error");
			goto end;
		}
	}
	
	a=strlen(s);
	if(a==0)
	{
		printf("error");
	}
	
	else
	{
		for(i=0;s[i]!='\0';i++)
     	{
		    if(s[i]<87||(s[i]>96&&s[i]<119))
	        {
	   	    	c[i]=s[i]+4;
	    	}
		    else
		    {
		    	c[i]=s[i]-22;
		    }
	    }
	    
	    	printf("%s",c);
	}
    end:
    return 0;
}
