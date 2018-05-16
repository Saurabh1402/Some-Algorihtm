#include<stdio.h>
#include<malloc.h>
int main(){
	int testCase,no,sum;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d",&no);
		sum=0;
		while(no){
			sum+=no%10;
			no/=10;
		}
		printf("%d\n",sum);
	}
	return 0;
}
