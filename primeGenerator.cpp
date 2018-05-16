#include<stdio.h>
#include<math.h>
void checkPrime(int);
int main(){
	int testCase;
	scanf("%d",&testCase);
	int m[testCase],n[testCase];
	for (int i = 0; i <testCase ; i++)
	{
		scanf("%d%d",&m[i],&n[i]);
	}
	for (int i = 0; i <testCase ; i++)
	{
		for (int j = m[i]; j <=n[i] ; j++)
		{	
			if(j==1)continue;
			checkPrime(j);
		}
		printf("\n");
	}
	
	
}
void checkPrime(int p){
	int sq_p=(int)sqrt(p);
	for (int i = 2; i <=sq_p ; i++)
	{
		if(p%i==0){
			return;
		}
	}
	printf("%d\n",p);
	
}
