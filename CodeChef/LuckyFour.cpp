#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main(){
	int testCase;
	char *a=(char *)malloc(sizeof(char));
	int count,length;
	scanf("%d",&testCase);
	while(testCase--){
		count=0;
		fflush(stdin);
		scanf("%s",a);
		length=strlen(a);
		while(length--){
			if(a[length]=='4')
				count++;
		}
		printf("%d\n",count);
		
	}
	return 0;
}
