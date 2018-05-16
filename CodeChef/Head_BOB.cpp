#include<stdio.h>
#include<malloc.h>
int main(){
	int flag=2,testCase,length;
	char *c=(char *)malloc(sizeof(char));
	scanf("%d",&testCase);
	while(testCase--){
	scanf("%d",&length);
	scanf("%s",c);
	flag=2;
	while(length--){
	 if(c[length]=='I'){
			flag=1;
			break;
	 }
	 if(c[length]=='Y'){
		flag=0;
		break;
	 }
	}
	if(flag==1)
	printf("INDIAN\n");
	else if(flag==0)
		printf("NOT INDIAN\n");
	else
		printf("NOT SURE\n");
	
	}
	
}
