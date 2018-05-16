#include<stdio.h>
int main(){
	int sum,div,testCase,no;
	scanf("%d",&testCase);
	while(testCase--){
		sum=0;
		scanf("%d",&no);
		sum+=no%10;
		div=10;
		while(no/div!=0)	
			div*=10;
		div/=10;
		sum+=no/div;
		printf("%d\n",sum);
	}
	return 0;
}
