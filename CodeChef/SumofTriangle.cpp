#include<stdio.h>
int main(){
	int testCase;
	int size;
	scanf("%d",&testCase);
	int ans[testCase],max,temp;
	for (int i = 0; i <testCase; i++)
	{	ans[i]=0;
		scanf("%d",&size);
		
		for (int j = 0; j <size ; j++)
		{	max=-1;
			for (int k = 0; k <=j ; k++)
			{
				scanf("%d",&temp);
				if(temp>max)
					max=temp;
			}
			ans[i]+=max;
			
		}
		
		
	}
	for (int i = 0; i < testCase; i++)
	{
		printf("%d\n",ans[i]);
	}
	
	
	return 0;
}
