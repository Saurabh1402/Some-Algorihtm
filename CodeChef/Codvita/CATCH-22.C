#include<stdio.h>
#include<math.h>
#include<malloc.h>

int main()
{
   float *F,*B,*T,*FD,*BD;
   float N,t,s,a,b;
	int i;
   scanf ("%f",&N);
   F = (float *) malloc (sizeof (float) * N);
   B = (float *) malloc (sizeof (float) * N);
   T = (float *) malloc (sizeof (float) * N);
   FD = (float *) malloc (sizeof (float) * N);
   BD = (float *) malloc (sizeof (float) * N);
   for (i=0;i<N;i++)
	scanf("%f %f %f %f %f",&F[i],&B[i],&T[i],&FD[i],&BD[i]);
   for (i=0;i<N;i++)
   {
	if (F[i] > B[i])
	{
		t = (ceil ((FD[i] - F[i])/(F[i] - B[i]))) * (F[i] + B[i]);
		s = FD[i] - (F[i] - B[i]);
		printf ("%.0f F\n",(t + s) * T[i]);
	}
	else if (F[i] < B[i])
	{
		a = floor ( BD[i]/(B[i] - F[i]) );
		t = a * (F[i] + B[i]);
		if ((int)BD[i] % (int)(B[i] - F[i]) == 0)
			b = 0;
		else
			b = 2 * F[i];
		s = BD[i] - (a * (B[i] - F[i]));
		printf ("%.0f B\n",(b + t + s) * T[i]);
	}
	else if (F[i] == B[i])
	{
		if ((F[i] - FD[i]) > 0)
		{
			printf ("%.0f F",FD[i] * T[i]);
		}
		else
		{
			printf("No Ditch\n");
		}
	}
   }
   return 0;
}
