#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main(){
	int testCase,length,flag;
	char *a,*b;
	scanf("%d",&testCase);
	while(testCase--){
		a=(char *)malloc(sizeof(char));
		b=(char *)malloc(sizeof(char));
		scanf("%s",a);
		scanf("%s",b);
		length=strlen(a);
		while(length>=0){
			flag=1;
			if(a[length]==b[length]||a[length]=='?'||b[length]=='?'){
				length--;
			}
			else{
				flag=0;
				printf("No\n");
				break;
			}
			
			
			
		}
		if(flag==1){
				printf("Yes\n");
			}
		
	}
	return 0;
	}
