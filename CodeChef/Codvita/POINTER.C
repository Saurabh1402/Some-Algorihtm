#include<stdio.h>
#include<malloc.h>

//conio.h hata lena upar se :)

void insertInBST(struct BSTNode**,int );
void inorderTraversal(struct BSTNode *);
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
	struct BSTNode *root=NULL;
	//Tum upar wali statement main root ko NULL initialize karna bhool gaye the
	//Isliye tree ke inorder traversal main 0 aa raha tha starting main
	int *c,b,*q;
	int i,a[]={34,26,17,2432,78,56,45,11,45,23,167,981,1};
	//Upar wale pointers ekdum sahi kaam kar rahe hain

	for (i=0;i<13;i++)
		insertInBST(&root,a[i]);
	inorderTraversal(root);
	b=11;
	q=&b;
	printf("%d\n",b);
	*q=22;
	printf("%d\n",b);
	c=q;
	*c=33;
	printf("%d\n",b);
	//printf("\n%d",root->data);
	//printf("\n%d",root->data);
	return 0;
}
void insertInBST(struct BSTNode **root,int a){
	if(*root == NULL){
		*root = (struct BSTNode*)malloc(sizeof(struct BSTNode));
		(*root)->data=a;
		(*root)->left= (*root)->right= NULL;
	}
	else{
		 
		 if((*root)->data < a){
			insertInBST (&((*root)->right),a);
		}
		else {
			insertInBST (&((*root)->left),a);
		}
	}
	return;
}

void inorderTraversal(struct BSTNode *root){
	if(root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%d ",root->data);
	inorderTraversal(root->right);
}
