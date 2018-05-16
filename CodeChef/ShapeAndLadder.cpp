#include<stdio.h>
#include<math.h>
int main(){
	int testCase;
	int a,b;
	scanf("%d",&testCase);
	float ans[testCase][2];
	for (int i = 0; i < testCase; i++)
	{
		scanf("%d %d",&a,&b);
		ans[i][0]=(float)sqrt(b*b-a*a);
		ans[i][1]=(float)sqrt(b*b+a*a);
	}
	for (int i = 0; i <testCase ; i++)
	{
		printf("%f %f\n",ans[i][0],ans[i][1]);
	}
	
	return 0;
}
