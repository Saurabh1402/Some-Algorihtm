#include<stdio.h>
#include<malloc.h>
void makeSet(int[],int );
int findSet(int[],int,int);
void unionSet(int[],int,int,int);
void makeSet(int S[],int size){
		int i;
		for (i = 0; i <size; i++)
		{
			S[i]=i;
		}
}
int findSet(int S[],int size,int x){
	if(!(x>=0 && x <size))
		return -1;
	if(S[x]==x)
		return x;
	else
		return findSet(S,size,S[x]);
}
void unionSet(int S[],int size,int index1,int index2){
	if(findSet(S,size,index1)==findSet(S,size,index2))
		return;
	if(!((index1>=0 && index1<size) && (index2>=0 && index2<size)))
		return;
	S[findSet(S,size,index1)]=findSet(S,size,index2);
	
}
