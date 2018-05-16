#include<stdio.h>
#define MAX 100
#define NIL -1
int memo[100];
void initialize(){
	for (int i = 0; i < MAX; i++)
	{
		memo[i]=NIL;
	}
	
}
int fib(int n){
	if(memo[n]==NIL){
		if(n<=1){
			memo[n]=n;
		}else{
			memo[n]=fib(n-1)+fib(n-2);
			
		}
	}
	return memo[n];
}
int main(){
	int n=20;
	initialize();
	fib(n);
	for (int i = 1; i < n; i++)
	{
		printf(" %d ",memo[i]);
	}
	
}
