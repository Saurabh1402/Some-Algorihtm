#include<stdio.h>
int main(){
	int a[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
	int testCase;
	int p,j;
	scanf("%d",&testCase);
	int ans[testCase];
	
	for (int i = 0; i < testCase; i++)
	{
		scanf("%d",&p);
		ans[i]=0;
		j=11;
		while(j>=0){
			ans[i]=ans[i]+(p/a[j]);
			p%=a[j];
			j--;
		}
	}
	for (int i = 0; i <testCase; i++)
	{
		printf("%d\n",ans[i]);
	}
	
	return 0;
}
