#include<stdio.h>
#include<string.h>
int main()
{
char shuyi[20];
char shuer[20];
int shuyiplus[20];
int shuerplus[20];
scanf("%s",&shuyi);
scanf("%s",&shuer);
int a = strlen(shuyi);
int b = strlen(shuer);
int c=0;
int d=0;
for(c=0;c<a;)
{
shuyi[c] = shuyiplus[c];
c++;
}
for(c>=a&&c<20;;)
{
shuyiplus[c]=0;
c++;
}
for(d=0;d<b;)
{
shuyi[d] = shuyiplus[d];
c++;
}
for(d>=b&&d<20;;)
{
shuerplus[d]=0;
d++;
}
int shuhe[20]; 
int e;
for(e=0;e<20;e++)
if (shuyiplus[e]+shuerplus[e]<10)
{
shuhe[e]=shuyiplus[e]+shuerplus[e];
}
else
{
shuyiplus[e+1]=shuyiplus[e+1]+1;
shuhe[e]=shuyiplus[e]+shuerplus[e]-10;
}
int f;
char shuheaaa[20];
for(f=0;f<20;f++)
{
shuheaaa[19-f]=shuhe[f];
}
printf("%s\n",shuheaaa);
return 0;

 } 
