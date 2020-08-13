//下列程序的功能是输出一百以内能被3整除且个位为6的整数 
#include<iostream>
using namespace std;
int main()
{
   int i,j;
   for(i =0;i<10;i++){
       j = i*10 +6;
	 if(j%3!=0)continue;
	 cout<<j;
   }
   return 0;
}
