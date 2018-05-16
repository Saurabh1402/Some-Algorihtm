#include<stdio.h>
int main(){
	int testCase,m,k,n,temp,temp1,a,b;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d%d%d",&n,&m,&k);
		int am[m];
		int ak[k];
		for (int i = 0; i < m; i++)
		{
			scanf("%d",&am[i]);
		}
		for (int i = 0; i < k; i++)
		{
			scanf("%d",&ak[i]);
		}
		a=0;
		b=0;
		temp=0;
		temp1=0;
		for (int i = 1; i <=n ; i++)
		{
			if(temp<m && am[temp]==i){
				if(ak[temp1]==i){
					a++;
					temp1++;
					temp++;
					continue;
				}
				temp++;
				
			}else if(temp1<k && ak[temp1]==i){
				temp1++;
				continue;
			}else{
				b++;
			}
		}
		printf("%d %d\n",a,b);
		
		
	}
	return 0;
}
