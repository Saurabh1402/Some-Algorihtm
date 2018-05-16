#include<stdio.h>
#include<string.h>
#include<malloc.h>

void inorderTravesal(struct BSTNode *);
void inorderTravesalWithCounter(struct BSTNode *,int);
struct BSTNode** insertInBST(struct BSTNode **,int);
struct BSTNode{
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
};

struct BSTNode* insertInBST(struct BSTNode *root,int a){
	struct BSTNode *newNode=(struct BSTNode *)malloc(sizeof(struct BSTNode));
	newNode->data=a;
	newNode->left=newNode->right=NULL;
	if(!root){
		root=newNode;
		return root;
	}
	if(root->data<a){
			root->right=insertInBST(root->right,a);
		}
	else {
		root->left=insertInBST(root->left,a);
		}
		return root;
	}
int main(){
	struct BSTNode *root=NULL;
	root=insertInBST(root,23);
	root=insertInBST(root,234);
	root=insertInBST(root,12);
	root=insertInBST(root,53);
	root=insertInBST(root,6346);
	root=insertInBST(root,45);
	root=insertInBST(root,1);
	root=insertInBST(root,65);
	root=insertInBST(root,144);
	root=insertInBST(root,255);
	inorderTravesalWithCounter(root,2);
return 0;
}
void inorderTravesal(struct BSTNode *root){
	if(!root)
		return;
	inorderTravesal(root->left);
	printf("%d ",root->data);
	inorderTravesal(root->right);
	
	
}
void inorderTravesalWithCounter(struct BSTNode *root,int max){
	static int count=0;
	if(!root)
		return;
	inorderTravesalWithCounter(root->left,max);
	count++;
	if(count>max)return;
	printf("%d ",root->data);
	inorderTravesalWithCounter(root->right,max);
	
	
}
