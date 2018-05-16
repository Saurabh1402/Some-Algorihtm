#include<stdio.h>
int main(){
	int testCase,no,min,second,a;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d",&no);
		min=100001;
		second=100001;
		scanf("%d",&a);
		min=a;
		scanf("%d",&a);
		if(a<min){
			second=min;
			min=a;
		}
		else{
			min=a;
		}
		for (int i = 2; i <no; i++)
		{
			scanf("%d",&a);
			if(a<min){
				second=min;
				min=a;
			}else if(a<second){
				second=a;
			}
		}
		printf("%d\n",min+second);
		
	}
	return 0;
}
