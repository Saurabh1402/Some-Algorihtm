#include<stdio.h>
int max(int ,int);
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int testCase,a,b;
	scanf("%d",&testCase);
	int ans[testCase][2];
	for (int i = 0; i <testCase;i++)
	{
		scanf("%d %d",&a,&b);
		ans[i][0]=max(a,b);
		ans[i][1]=a+b;
	}
	for (int i = 0; i < testCase; i++)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	
}
