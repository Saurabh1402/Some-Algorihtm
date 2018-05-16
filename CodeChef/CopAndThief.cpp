#include<stdio.h>
int main(){
	int testCase,m,x,y;
	int a[100],count;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d%d%d",&m,&x,&y);
		int ar[m];
		for (int i = 0; i < 100; a[i++]=0);
		
		for (int i = 0; i <m ; i++)
		{
			scanf("%d",&ar[i]);
		}
		for (int i = 0; i <100 ; i++)
		{
			for (int j = 0; j <m; j++)
			{
				if((ar[j]-x*y-1)<=i&&i<=(ar[j]+x*y-1))
				a[i]=1;
			}
			
		}
		count=0;
		for (int i = 0; i < 100; i++)
		{
			if(a[i]==0)	
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
