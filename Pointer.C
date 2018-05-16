#include<stdio.h>
#include<malloc.h>
void insertInBST(struct BSTNode**,int );
void inorderTravesal(struct BSTNode *);
struct BSTNode* maxNode(struct BSTNode *);
struct BSTNode* minNode(struct BSTNode *);
struct BSTNode* maxNodePredecessor(struct BSTNode *);
struct BSTNode* minNodeSuccessor(struct BSTNode *);

struct BSTNode{
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
};
int main(){
	struct BSTNode *root;
	int *c,b,*q;
	int i,a[]={34,26,17,2432,78,56,45,11,45,23,167,981,1};
// From here
					b=11;
					q=&b;
					printf("%d\n",b);
					*q=22;
					printf("%d\n",b);
					c=q;
					*c=33;
					printf("%d\n",b);
// To Here
	for(i=0;i<13;i++)
		insertInBST(&root,a[i]);
	inorderTravesal(root);
	//printf("\n%d",root->data);
	//printf("\n%d",root->data);
	return 0;
}
void insertInBST(struct BSTNode **root,int a){
	if(*root==NULL){
		*root=(struct BSTNode*)malloc(sizeof(struct BSTNode));
		(*root)->data=a;
		(*root)->left=(*root)->right=NULL;
		return;
	}
	else{
		 struct BSTNode *newNode=(struct BSTNode *)malloc(sizeof(struct BSTNode));
		 newNode->data=a;
		 newNode->left=newNode->right=NULL;
	
		 if((*root)->data<a){
				insertInBST(&((*root)->right),a);
		}
		else {
			insertInBST(&((*root)->left),a);
		}
	}
	return;
}

void inorderTravesal(struct BSTNode *root){
	if(!root)
		return;
	inorderTravesal(root->left);
		printf("%d ",root->data);
	inorderTravesal(root->right);
	
}
