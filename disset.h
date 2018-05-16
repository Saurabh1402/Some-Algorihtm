#include<stdio.h>
#include<malloc.h>
void makeSet(int[],int );
int findSet(int[],int,int);
void unionSet(int[],int,int,int);
/*
 int main(){
				int ch,i,S[10],j;
				int size=10;
				while(1){
					printf("\n1-->MAKESET\n2-->FINDSET\n3-->UNION\n4-->PRINT the array\n5-->EXIT\nEnter Your Choice: ");
					scanf("%d",&ch);
					switch(ch){
						case 1:
								makeSet(S,size);
								break;
						case 2:
								printf("\nEnter the Index to Find Set");
								scanf("%d",&i);
								printf("\n%d",findSet(S,size,i));
								break;
						case 3:
								printf("\nEnter the indices <index 1,index 2>");
								scanf("%d%d",&i,&j);
								unionSet(S,size,i,j);
								break;
						case 4:
								printf("\n");
								for (int i = 0; i < size; i++)
								{
									printf("%d ",S[i]);
								}
								
								break;
					}
				}
				return 0;
			}

 */
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
