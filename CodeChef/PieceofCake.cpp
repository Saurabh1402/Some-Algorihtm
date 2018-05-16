#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main(){
	int testCase,len,length,max;
	char ch[26];
	char *s=(char *)malloc(sizeof(char)*50);
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%s",s);
		len=length=strlen(s);
		if(length%2==1){
			printf("NO\n");
			continue;
		}
		for (int i = 0; i <26 ; ch[i++]=0);
		while(length--){
				ch[s[length]-97]++;
				
		}
		for (int i = 0; i < 26; i++)
		{
			if(ch[i]>max){
				max=ch[i];
			}
		}
		if(len/2==max)
		printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
