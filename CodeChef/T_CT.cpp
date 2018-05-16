#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main(){
	int testCase,length;
	int alph[26],counter;
	char *c=(char *)malloc(sizeof(char)*100000);
	scanf("%d",&testCase);
	while(testCase--){
		for (int i = 0; i <26; alph[i++]=0);
		scanf("%s",c);
		length=strlen(c);
		counter=0;
		while (length--)
		{
			if(alph[c[length]-97]==0){
				alph[c[length]-97]++;
				counter++;
			}
		}
		if(counter%2==1)
			printf("Counter Terrorist\n");
		else
			printf("Terrorist\n");
	}
	
}
