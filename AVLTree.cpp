#include<stdio.h>
#include<malloc.h>
struct AVLTreeNodeInt** insertInAVLTreeInt(struct AVLTreeNodeInt**,struct AVLTreeNodeInt **,int );
void inOrderTraversalInt(struct AVLTreeNodeInt *);
void preOrderTraversalInt(struct AVLTreeNodeInt *);
void postOrderTraversalInt(struct AVLTreeNodeInt *);
void levelOrderTraversalInt(struct AVLTreeNodeInt *);

struct AVLTreeNodeInt* maxNodeInt(struct AVLTreeNodeInt *);
struct AVLTreeNodeInt* minNodeInt(struct AVLTreeNodeInt *);
struct AVLTreeNodeInt* maxNodeInorderIntPredecessor(struct AVLTreeNodeInt *);
struct AVLTreeNodeInt* minNodeInorderIntSuccessor(struct AVLTreeNodeInt *);

struct AVLTreeNodeInt* findNodeInt(struct AVLTreeNodeInt*,int );
struct AVLTreeNodeInt* findNodeParentInt(struct AVLTreeNodeInt*,int );
struct AVLTreeNodeInt* findNodeInorderIntPredecessor(struct AVLTreeNodeInt* ,int);
struct AVLTreeNodeInt* findNodeInorderIntSuccessor(struct AVLTreeNodeInt* ,int);
struct AVLTreeNodeInt* singleRotationLeft(struct AVLTreeNodeInt *);
struct AVLTreeNodeInt* singleRotationRight(struct AVLTreeNodeInt *);
struct AVLTreeNodeInt* DoubleRotationLeft(struct AVLTreeNodeInt *);
struct AVLTreeNodeInt* DoubleRotationRight(struct AVLTreeNodeInt *);
int maxHeight(struct AVLTreeNodeInt*,struct AVLTreeNodeInt*);
int Height(struct AVLTreeNodeInt *);
int max(int ,int );
struct AVLTreeNodeInt{
	int data;
	int height;
	struct AVLTreeNodeInt *left;
	struct AVLTreeNodeInt *right;
};

		int main(){
			int i,a[]={34,26,17,2432,78,56,45,11,45,23,167,981,1};
			struct AVLTreeNodeInt *root=NULL;
			for(i=0;i<13;i++)
				insertInAVLTreeInt(&root,NULL,a[i]);
			inOrderTraversalInt(root);
			return 0;
		}

struct AVLTreeNodeInt** insertInAVLTreeInt(struct AVLTreeNodeInt **root,struct AVLTreeNodeInt **parent,int a){
	struct AVLTreeNodeInt *newNode=(struct AVLTreeNodeInt *)malloc(sizeof(struct AVLTreeNodeInt));
	
	newNode->data=a;
	newNode->left=newNode->right=NULL;
	if(!*root){
		newNode->height=0;
		*root=newNode;
		return root;
	}

	if((*root)->data<a){
			insertInAVLTreeInt(&((*root)->right),root,a);
			//printf("Left: %d %d\n",Height((*root)->right),Height((*root)->left));
			if(Height((*root)->right)-Height((*root)->left)>=2){
				if(a>(*root)->right->data)
					*root=singleRotationRight((*root));
				else if(a<(*root)->right->data)
					*root=DoubleRotationRight((*root));
			}
		}
	else if((*root)->data > a){
		insertInAVLTreeInt(&((*root)->left),root,a);
		//printf("Right: %d %d\n",Height((*root)->left),Height((*root)->right));
		if(Height((*root)->left)-Height((*root)->right)>=2){
			
			if(a < (*root)->left->data)
				*root=singleRotationLeft((*root));
			else  if(a>(*root)->left->data)
				*root=DoubleRotationLeft((*root));
		}
	}
	(*root)->height=maxHeight((*root)->left,(*root)->right)+1;
	return root;
}

void inOrderTraversalInt(struct AVLTreeNodeInt *root){
	if(!root)
		return;
	inOrderTraversalInt(root->left);
	printf("%d::%d  ",root->data,root->height);
	inOrderTraversalInt(root->right);
	
}
void preOrderTraversalInt(struct AVLTreeNodeInt *root){
	if(!root)
		return;
	printf("%d ",root->data);
	preOrderTraversalInt(root->left);
	preOrderTraversalInt(root->right);
	
}
void postOrderTraversalInt(struct AVLTreeNodeInt *root){
	if(!root)
		return;
	postOrderTraversalInt(root->left);
	postOrderTraversalInt(root->right);
	printf("%d ",root->data);
}
void levelOrderTraversalInt(struct AVLTreeNodeInt *root){
		
}

struct AVLTreeNodeInt* maxNodeInt(struct AVLTreeNodeInt *root){
	if(!root)
		return NULL;
	if(!root->right)
		return root;
	else return maxNodeInt(root->right);
	
}
struct AVLTreeNodeInt* minNodeInt(struct AVLTreeNodeInt *root){
	if(!root)
		return NULL;
	if(!root)return NULL;
	if(!root->left)
		return root;
	else return minNodeInt(root->left);
	
}
struct AVLTreeNodeInt* minNodeInorderIntSuccessor(struct AVLTreeNodeInt *root){
	
	return findNodeInorderIntSuccessor(root,minNodeInt(root)->data);
		/*
			if(root->left){
			if(!root->left->left){
				if(root->left->right)
					return minNodeInt(root->left->right);
				else return root;
				}
				
			else return minNodeInorderIntSuccessor(root->left);
			}else{
				return minNodeInt(root->right);	
			}
		*/
}
struct AVLTreeNodeInt* maxNodeInorderIntPredecessor(struct AVLTreeNodeInt *root){
	
	return findNodeInorderIntPredecessor(root,maxNodeInt(root)->data);
	
	/*		
			if(root->right){
			if(!root->right->right){
				if(root->right->left)
					return maxNodeInt(root->right->left);
				else return root;
				}
				
			else return maxNodeInorderIntPredecessor(root->right);
			}
			else{
				return maxNodeInt(root->left);	
			}
	*/
}

struct AVLTreeNodeInt* findNodeInt(struct AVLTreeNodeInt* bst,int data){
		if(bst==NULL){
			printf("Not Found! %d",data);
			return NULL;
		}
		if(bst->data==data){
			return bst;
		}
		if(bst->data<data) return findNodeInt(bst->right,data);
		else return findNodeInt(bst->left,data); 

}
struct AVLTreeNodeInt* findNodeParentInt(struct AVLTreeNodeInt* bst,int data){
		if(bst==NULL||(bst->data > data && bst->left==NULL)||(bst->data < data && bst->right==NULL)){
			printf("Not Found! %d",data);
			return NULL;
		}
		if(bst->data==data){
			printf("Data Found But Root Node...No Parent!:  %d",data);
				return NULL;
				}
		if(bst->left)
		if(bst->left->data==data){
			return bst;
		}
		if(bst->right)
		if(bst->right->data==data){
			return bst;
		}
		
		if(bst->data<data) return findNodeParentInt(bst->right,data);
		else return findNodeParentInt(bst->left,data); 
		
}
struct AVLTreeNodeInt* findNodeInorderIntPredecessor(struct AVLTreeNodeInt* bst,int data){
	
	static struct AVLTreeNodeInt * par=NULL;
	if(bst==NULL){
		printf("%d does not Exist!",data);
		return NULL;
		}
	if(bst->data==data){
		if(bst->left!=NULL){
			par=maxNodeInt(bst->left);
			printf("Predecessor of %d Found! %d",data,par->data);
			return par;
		}
		if(par==NULL){
				printf("Predecessor of %d Not Found! because it is Smallest",data);
				return NULL;
		}
		else {
			
			printf("Predecessor Found! %d",par->data);
			return par;
		}
	}
	else if(bst->data < data){
	
		par=bst;
		return findNodeInorderIntPredecessor(bst->right,data);
	
	}
	else {
		return findNodeInorderIntPredecessor(bst->left,data);
	} 
	
	
}
struct AVLTreeNodeInt* findNodeInorderIntSuccessor(struct AVLTreeNodeInt* bst,int data){
	static struct AVLTreeNodeInt *par=NULL;
	if(bst==NULL){
		printf("%d not Found!",data);
		return NULL;
	}
	if(bst->data==data){
		if(bst->right!=NULL){
			par=minNodeInt(bst->right);
			printf("successor of %d Found: %d\n",data,par->data);
			return par;
		}
		if(par!=NULL){
				printf("successor of %d Found: %d\n",data,par->data);
				return par;
		}
		if(par==NULL){
				printf("Predecessor of %d Not Found! because it is Largest",data);
				return NULL;
		}
		
	}
	else if(bst->data>data){
		par=bst;
		return findNodeInorderIntSuccessor(bst->left,data);
	}
	else{
		return findNodeInorderIntSuccessor(bst->right,data);
		}
	return NULL;
}
struct AVLTreeNodeInt* singleRotationLeft(struct AVLTreeNodeInt *X){
	struct AVLTreeNodeInt *W=X->left;
	X->left=W->right;
	W->right=X;
	X->height=maxHeight(X->left,X->right)+1;
	W->height=maxHeight(W->left,W->right)+1;
	return W;
}
struct AVLTreeNodeInt* singleRotationRight(struct AVLTreeNodeInt *X){
	struct AVLTreeNodeInt *W=X->right;
	X->right=W->left;
	W->left=X;
	X->height=maxHeight(X->left,X->right)+1;
	W->height=maxHeight(W->left,W->right)+1;
	return W;
}
struct AVLTreeNodeInt* DoubleRotationLeft(struct AVLTreeNodeInt *Z){
	Z->left=singleRotationRight(Z->left);
	return singleRotationLeft(Z);
}
struct AVLTreeNodeInt* DoubleRotationRight(struct AVLTreeNodeInt *Z){
	Z->right=singleRotationLeft(Z->right);
	return singleRotationRight(Z);
}
int maxHeight(struct AVLTreeNodeInt *left,struct AVLTreeNodeInt *right){
	return max(Height(left),Height(right));
}
int Height(struct AVLTreeNodeInt *root){
	if(!root)
		return -1;
	else 
		return root->height;
}
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
