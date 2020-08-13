/*编写完整程序，输入两个字符串，检查string1中是否包含
  string2中，如果有，则输出出现次数及每次出现的起始位置；
  如果没有，输出'no'*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	printf("请输入string1和string2");
	const int q = 100;
	int num[q],h=0;
	char word[q];
	char words[q];
	scanf_s("%s", word, q);
	scanf_s("%s", words, q);
	int a, b, i, j, k, l,p;
	a = strlen(word);
	b = strlen(words);
	l = a - b + 1;
	for (i = 0; i <= l; i++) {
			for (j = i; j <= b+i-1; j++) {
				if (word[j] == words[j-i]) continue;
				else {
					k = l - 1;
					goto end;
				}
		}
			num[h] = i;
			h++;
		end:;
	}
	if (k == 0) {
		printf("NO");
	}
	else {
		printf("%d\n", k);
		for (p = 0; p < h; p++) {
			printf("%d", num[p]);
		}
	}

}
