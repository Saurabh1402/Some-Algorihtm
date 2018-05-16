#include<stdio.h>
#include<math.h>

int main()
{
   double a,d,X,Y;

   scanf ("%lf %lf",&a,&d);
   if ((a <= 0 || a > (double)(57 * d)) || (d <= 0 || d > (double)(1.7 * a)))
   {
		printf ("\nInvalid Input");
		return 0;
   }
   X = a - ((double)d / pow(3,0.5));
   Y = (double)(2 * d)/pow(3,0.5);
   printf("X= %.11lf\n",X);
   printf("Y= %.11lf",Y);
   return 0;
}
