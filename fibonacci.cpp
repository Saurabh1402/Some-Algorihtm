#include<stdio.h>
#include<malloc.h>
void fibonacci(int n){
	int i,f[n+1];
	f[1]=1;
	f[2]=1;
	for (i = 2; i <=n ; i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	for (int i = 1; i <=n ; i++)
	{
		printf("%d ",f[i] );
	}
	
}
int main(){
	fibonacci(20);
	
}
