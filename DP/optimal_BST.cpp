#include<stdio.h>
#include<limits.h>
#include "bstint.h"
int optimalBST(int A[],int F[],int l,int r,struct BTNodeInt **proot){
	if(l>r)
		return 0;
	struct BTNodeInt *root=*proot,*left=NULL,*right=NULL;
		root=(struct BTNodeInt *)malloc(sizeof(struct BTNodeInt));
	if(!root)
	{
		printf("Memory Error: 11");
		return -1;
	}
	int f_value=0,min_value,current_value,left_value,right_value;
	min_value=INT_MAX;
	for (int i = l; i <=r; i++)
	{	f_value=0;
		left=right=NULL;
		left_value=optimalBST(A,F,l,i-1,&left);
		right_value=optimalBST(A,F,i+1,r,&right);
		for (int j = l; j <=r ; j++)
		{
			f_value+=F[j];
		}
		current_value=left_value+right_value+f_value;
		if(min_value>current_value){
			min_value=current_value;
			root->left=left;
			root->right=right;
			root->data=A[i];
		
		}
	}
	*proot=root;
	return min_value;
	
}
int main(){
	int A[]={10,12,20};
	int F[]={34,8,50};
	
	struct BTNodeInt *root=NULL;
	printf("Min Value: %d ",optimalBST(A,F,0,2,&root));
	inOrderTraversalInt(root);
	printf("\n");
	preOrderTraversalInt(root);
	return 0;
	}
