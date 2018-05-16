#include<stdio.h>
int main(){
	int testCase;
	int no,temp=1;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d",&no);
		temp=1;
		if(no==1){
			printf("2\n");
			continue;
		}
		while(temp<no)
			temp*=2;
		if(temp-1==no)
		printf("%d\n",temp/2-1);
		else
			printf("-1\n");
		
	}
	return 0;
}
