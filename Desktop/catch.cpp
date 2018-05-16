#include<stdio.h>
#include<math.h>
#include<malloc.h>

int main()
{
   int *F,*B,*T,*FD,*BD;
   int N,t,s,a,b;
	int i;
   scanf ("%d",&N);
   F = (int *) malloc (sizeof (int) * N);
   B = (int *) malloc (sizeof (int) * N);
   T = (int *) malloc (sizeof (int) * N);
   FD = (int *) malloc (sizeof (int) * N);
   BD = (int *) malloc (sizeof (int) * N);
   for (i=0;i<N;i++)
	scanf("%d %d %d %d %d",&F[i],&B[i],&T[i],&FD[i],&BD[i]);
   for (i=0;i<N;i++)
   {
	if (F[i] > B[i])
	{
		t = (ceil ((FD[i] - F[i])/(F[i] - B[i]))) * (F[i] + B[i]);
		s = FD[i] - ((F[i] - B[i]) * ceil ((FD[i] - F[i])/(F[i] - B[i])));
		printf ("%d F\n",(t + s) * T[i]);
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
		printf ("%d B\n",(b + t + s) * T[i]);
	}
	else if (F[i] == B[i])
	{
		if ((F[i] - FD[i]) > 0)
		{
			printf ("%d F\n",FD[i] * T[i]);
		}
		else
		{
			printf("No Ditch\n");
		}
	}
   }
   return 0;
}
