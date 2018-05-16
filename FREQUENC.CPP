#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include "qsort.h"
#define TRUE 1
#define FALSE 0

int main(){
	char ar[]="saurabh vishwakarma";
	int a[]={1,2,4,3,1,5,1};
	quickSortInt(a,0,6);
	quickSortChar(ar,0,18);
	printIntArray(a,7);
	printCharArray(ar,19);

	return 0;
}
