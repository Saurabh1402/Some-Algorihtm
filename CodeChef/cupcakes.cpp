#include<stdio.h>
int main(){
	int testCase,cupcakes;
	scanf("%d",&testCase);
	int ar[testCase];
	for (int i = 0; i <testCase ; i++)
	{
		scanf("%d",&cupcakes);
		ar[i]=cupcakes/2+1;
	}
	for (int i = 0; i < testCase; i++)
	{
		printf("%d\n",ar[i]);
	}
	return 0;
}
