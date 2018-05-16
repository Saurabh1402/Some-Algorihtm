#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct BSTNode** insertInBST(struct BSTNode **,int);
void inorderTravesal(struct BSTNode *);
struct BSTNode* maxNode(struct BSTNode *);
struct BSTNode* minNode(struct BSTNode *);
struct BSTNode* maxNodePredecessor(struct BSTNode *);
struct BSTNode* minNodeSuccessor(struct BSTNode *);
int deleteNode(struct BSTNode *);


struct BSTNode{
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
};

int main(){
	struct BSTNode *root;
	int a[]={34,45,78,12,23,78,33,44,76,89,1,12,11,99};
	int i,data,K_MAX=5,n=14;
	for(i=0;i<K_MAX;i++){
			insertInBST(&root,a[i]);
	}
	inorderTravesal(root);
	for(i=K_MAX;i<n;i++){
		data=maxNode(root)->data;
		if(a[i]>data){
		continue;
		}
		else{
			}
		
	}
	
	printf("\n");
	
return 0;
}
struct BSTNode** insertInBST(struct BSTNode **root,int a){
	struct BSTNode *newNode=(struct BSTNode *)malloc(sizeof(struct BSTNode));
	newNode->data=a;
	newNode->left=newNode->right=NULL;
	if(!*root){
		*root=newNode;
		return root;
	}
	if((*root)->data<a){
			insertInBST(&((*root)->right),a);
	}
	else {
		insertInBST(&((*root)->left),a);
	}
	return root;
}

void inorderTravesal(struct BSTNode *root){
	if(!root)
		return;
	inorderTravesal(root->left);
		printf("%d ",root->data);
	inorderTravesal(root->right);
	
}
struct BSTNode* maxNode(struct BSTNode *root){
	if(!root->right)
		return root;
	else return maxNode(root->right);
	
}
struct BSTNode* minNode(struct BSTNode *root){
	if(!root)return NULL;
	if(!root->left)
		return root;
	else return minNode(root->left);
	
}
struct BSTNode* minNodeSuccessor(struct BSTNode *root){
	if(root->left){
	if(!root->left->left){
		if(root->left->right)
			return minNode(root->left->right);
		else return root;
		}
		
	else return minNodeSuccessor(root->left);
	}else{
		return minNode(root->right);	
	}

}
struct BSTNode* maxNodePredecessor(struct BSTNode *root){
	if(root->right){
	if(!root->right->right){
		if(root->right->left)
			return maxNode(root->right->left);
		else return root;
		}
		
	else return maxNodePredecessor(root->right);
	}
	else{
		return maxNode(root->left);	
	}

}

int deleteNode(struct BSTNode *root){
	struct BSTNode *temp=maxNodePredecessor(root),*max=maxNode(root);
	if(!max->left && !max->right){
		if(temp->left==max)
			temp->left=NULL;
		else if(temp->right==max)
			temp->right=NULL;
		int data= max->data;
		free (max);
		return data;
	}
	else if(!max->right){
		int data=deleteNode(maxNode(root->left));
		max->data=data;
	}
	else{
		
		}
			
	return 0;
}

