#include<stdio.h>
#include<math.h>
int main()
{
	long int temp2,p,q,temp,sol,T,x,y,t,max_insect_size,z;
	scanf("%ld",&T);
	while (T--)
	{
		scanf("%ld %ld %ld",&x,&y,&t);
		max_insect_size = z = 0;
		max_insect_size	 = y + 2*x;
		if(t>19){
			p = t/19;
			q = t%19;
			temp = (long int)pow (3,19) % 1000000007;
			temp2 = ((long int)(pow (temp,p) * pow(3,q))) % 1000000007 ;
			sol =  temp2 *(max_insect_size-x)+x;
		}
		else
			sol = pow (3,t-1) * (max_insect_size - x) + x;
		printf("%ld\n",sol%1000000007);
	}
	return 0;
}


