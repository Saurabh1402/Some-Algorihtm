#include<stdio.h>
#include<math.h>
#include<iostream>
#include<malloc.h>

int main(){
	char *c[5];
	for (int i =0; i<5 ; i++)
	{ c[i]=(char *)malloc(sizeof(char));
		scanf("%s",c[i]);
	}
	for (int i = 0; i <5; i++)
	{
		printf("%s",c[i]);
	}
	
	
}
