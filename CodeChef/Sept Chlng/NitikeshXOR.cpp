	#include<stdio.h>
	int main(){
		int no;
		scanf("%d",&no);
		int a[no],b[no][no],prev=0,sum1,sum2,max=-1,prev_max;
		for (int i = 0; i < no; i++)
		{
			scanf("%d",&a[i]);
			b[i][i+1]=a[i]^a[i+1];
			b[i][i]=a[i];
		}
		for(int i = 0; i <no-1; i++)
		{
			prev=a[i];
			prev_max=a[i];
			for(int j = i+1; j <no;j++)
			{
				prev=prev^a[j];
				if(prev>prev_max){
					prev_max=prev;
					b[i][j]=prev;
				}else{
					b[i][j]=prev_max;
				}
			}
		}
		for(int i = 0; i < no-1; i++)
		{
			sum1=0;
			
			for(int j = i; j < no; j++)
			{
				sum1=b[i][j];
				sum2=0;
				for (int k = j+1; k <no ; k++)
				{
					if(b[k][no-1]>sum2){
						sum2=b[k][no-1];
					}
				}
				sum1+=sum2;
				if(sum1>max)
					max=sum1;
			}
			
		}
		printf("%d",max);
		return 0;
	}
