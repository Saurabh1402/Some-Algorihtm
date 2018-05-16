#include<stdio.h>
#include<stdlib.h>

void check (int,int);
void quicksort(int,int);
int partition(int,int);
int H,W,*count,shantanu = 0;
char *mat;

int main()
{
	int T,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&H,&W);
		mat = (char *)malloc (sizeof(char) * H * W);
		count = (int *)malloc (sizeof(int) * H * W);
		for (i=0;i<H;i++)
			for (j=0;j<W;j++)
				*(count + i*W + j) = 0;
		for (i=0;i<H;i++)
		{
			for (j=0;j<W;j++)
			{
				scanf(" %c",(mat + i * W + j));	
			}
		}
		for (i=0;i<H;i++)
		{
			for (j=0;j<W;j++)
			{
				if (*(mat + i * W + j) == '#')
				{
					check (i,j);
					if (count[shantanu] > 0)
						shantanu++;
				}
			}
		}
		quicksort (0,shantanu-1);
		printf("%d\n",shantanu);
		for (i=0;i<shantanu;i++)
			printf("%d ",count[i]);
		printf("\n");
	}
	return 0;
}

void check (int p,int q)
{
	if (*(mat + p * W + q) == '#')
	{
		count[shantanu] = count[shantanu] + 1;
		*(mat + p * W + q) = '.';
		if ((p > 0) && (q > 0))
		{
			if (*(mat + p * W + q-1) == '#')
				check (p,q-1);
			if (*(mat + (p - 1)* W + q) == '#')
				check (p-1,q);
			if (*(mat + (p - 1)* W + q - 1) == '#')
				check (p-1,q-1);
			if (p < (H-1))
			{
				if (*(mat + (p + 1)* W + q) == '#')
					check (p+1,q);
				if (*(mat + (p + 1)* W + q - 1) == '#')
					check (p+1,q-1);
			}
			if (q < (W-1))
			{
				if (*(mat + (p - 1)* W + q + 1) == '#')
					check (p-1,q+1);
				if (*(mat + p * W + q + 1) == '#')
					check (p,q+1);
			}
			if ((p < (H-1)) && (q < (W-1)))
			{
				if (*(mat + (p + 1)* W + q + 1) == '#')
					check (p+1,q+1);
			}
		}
		else if ((p == 0) && (q > 0))
		{
			if (*(mat + p * W + q - 1) == '#')
				check (p,q-1);
			if (*(mat + (p + 1)* W + q) == '#')
				check (p+1,q);
			if (*(mat + (p + 1)* W + q - 1) == '#')
				check (p+1,q-1);
			if (q < (W-1))
			{
				if (*(mat + p * W + q + 1) == '#')
					check (p,q+1);
				if (*(mat + (p + 1)* W + q + 1) == '#')
					check (p+1,q+1);	
			}
		}
		else if ((p > 0) && (q == 0))
		{
			if (*(mat + (p - 1)* W + q) == '#')
				check (p-1,q);
			if (*(mat + p * W + q + 1) == '#')
				check (p,q+1);
			if (*(mat + (p - 1)* W + q + 1) == '#')
				check (p-1,q+1);
			if (p < (H-1))
			{
				if (*(mat + (p + 1)* W + q) == '#')
					check (p+1,q);
				if (*(mat + (p + 1)* W + q + 1) == '#')
					check (p+1,q+1);	
			}
		}
		else if ((p == 0) && (q == 0))
		{
			if (*(mat + p * W + q + 1) == '#')
				check (p,q+1);
			if (*(mat + (p + 1)* W + q) == '#')
				check (p+1,q);
			if (*(mat + (p + 1)* W + q + 1) == '#')
				check (p+1,q+1);
		}
	}
	return;
}

void quicksort (int left,int right)
{
   int pivot;
   if (left < right)
   {
	pivot = partition (left,right);
	quicksort (left,pivot-1);
	quicksort (pivot+1,right);
   }
}

int partition (int left,int right)
{
   int x = count[right],i = left - 1,j,temp;
   for (j=left;j<right;j++)
	if (count[j] <= x)
	{
	   i++;
	   temp = count[i];
	   count[i] = count[j];
	   count[j] = temp;
	}
   temp = count[i+1];
   count[i+1] = count[right];
   count[right] = temp;
   return i+1;
}
