#include<stdio.h>
int main(){
	int size,sum=0,testCase;
	scanf("%d",&testCase);
		
	while(testCase--){
		scanf("%d",&size);
		size=size/2;
		sum=0;
		while(size){
		sum+=size -1;
		size--;
		}
		printf("%d\n",sum);
	}
	return 0;
}
