#include<stdio.h>
int factorial(int n){
	int f[n+1];
	f[1]=1;
	for (int i = 2; i <=n ; i++)
	{
		f[i]=i*f[i-1];
		
	}
	return f[n];
}

int main(){
	printf("%d",factorial(6));
	
	return 0;
}
