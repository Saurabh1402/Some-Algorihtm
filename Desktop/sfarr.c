#include<stdio.h>

int main()
{
   long double M,T,R,x = 0;
   int i;
   scanf ("%Lf %Lf %Lf",&M,&T,&R);
   if ( (M <= 0) || (T <= 0) || (R < 0 ) )
   {
	printf("Invalid Input");
	return 0;
   }
   for (i = 0;i < T;i++)
	x = (x  + M)/(1 + (R / 1200));
   printf("%11.0Lf",x);
   return 0;
}