#include<stdio.h>
int main(){
	int rows,cols;
	int ar[999][999];
	while(1){
		scanf("%d",&rows);
		if(rows==0)
		break;
		scanf("%d",&cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				scanf("%d",&ar[i][j]);
			}
			
		}
		for (int i = 1; i <cols ; i++)
		{
			ar[0][i]=ar[0][i]+ar[0][i-1];
		}
		for (int i = 1; i <rows ; i++)
		{
			ar[i][0]+=ar[i-1][0];
		}
		
		for (int i = 1; i < rows; i++)
		{
			for (int j = 1; j < cols; j++)
			{
				if(ar[i][j-1]<ar[i-1][j])
					ar[i][j]+=ar[i][j-1];
				else
					ar[i][j]+=ar[i-1][j];
			}
			
		}
		
		printf("%d\n",ar[rows-1][cols-1]);
	}
	return 0;
}
