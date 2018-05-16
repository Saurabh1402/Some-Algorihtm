#include<stdio.h>
#include<math.h>

int main()
{
   long double a,d,X,Y;

   scanf ("%Lf %Lf",&a,&d);
   if ((a <= 0 || a > (long double)(57 * d)) || (d <= 0 || d > (long double)(1.7 * a)))
   {
	printf ("Invalid Input");
	return 0;
   }
   X = a - ((long double)d / pow(3,0.5));
   Y = (long double)(2 * d)/pow(3,0.5);
   printf("X= %.11Lf\n",X);
   printf("Y= %.11Lf",Y);
   return 0;
}
