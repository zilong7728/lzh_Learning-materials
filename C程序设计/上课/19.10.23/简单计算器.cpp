#include<stdio.h>
int main()
{
	int a,b,c;
	char op;
	scanf("%d %c %d",&a,&op,&b);
	switch ((int)op)
	{
		case 43:
		    c=a+b;
		    break;
	    case 45:
		    c=a-b;
		    break;
	    case 42:
	    	c=a*b;
	    	break;
	    case 47:
	    	c=a/b;
	    	break;
	    case 37:
	    	c=a%b;
	    	break;
        default:printf("error");
	} 
	printf("%d",c);
	return 0;
}
