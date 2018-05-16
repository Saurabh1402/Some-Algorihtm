#include<stdio.h>
#include<malloc.h>
struct BTNodeInt** insertInBSTInt(struct BTNodeInt**,int );
void inOrderTraversalInt(struct BTNodeInt *);
void preOrderTraversalInt(struct BTNodeInt *);
void postOrderTraversalInt(struct BTNodeInt *);
void levelOrderTraversalInt(struct BTNodeInt *);

struct BTNodeInt* maxNodeInt(struct BTNodeInt *);
struct BTNodeInt* minNodeInt(struct BTNodeInt *);
struct BTNodeInt* maxNodeInorderIntPredecessor(struct BTNodeInt *);
struct BTNodeInt* minNodeInorderIntSuccessor(struct BTNodeInt *);

struct BTNodeInt* findNodeInt(struct BTNodeInt*,int );
struct BTNodeInt* findNodeParentInt(struct BTNodeInt*,int );
struct BTNodeInt* findNodeInorderIntPredecessor(struct BTNodeInt* ,int);
struct BTNodeInt* findNodeInorderIntSuccessor(struct BTNodeInt* ,int);
struct BTNodeInt{
	int data;
	struct BTNodeInt *left;
	struct BTNodeInt *right;
};
/*
		int main(){
			int i,a[]={34,26,17,2432,78,56,45,11,45,23,167,981,1};
			int find=981;
			struct BTNodeInt *root=NULL;
			for(i=0;i<13;i++)
				insertInBSTInt(&root,a[i]);
			inOrderTraversalInt(root);
			minNodeInorderIntSuccessor(root);
			maxNodeInorderIntPredecessor(root);
			printf("\n");
			findNodeInorderIntSuccessor(root,26);
			if(findNodeInt(root,2432)!=NULL)printf("\nFind Node:	%d",findNodeInt(root,2432)->data);
			if(findNodeParentInt(root,find)){
				printf("\n-------------------------------------------\n");
				printf("\nParent of %d:	%d",find,findNodeParentInt(root,find)->data);
			}
			return 0;
		}
*/
struct BTNodeInt** insertInBSTInt(struct BTNodeInt **root,int a){
	struct BTNodeInt *newNode=(struct BTNodeInt *)malloc(sizeof(struct BTNodeInt));
	newNode->data=a;
	newNode->left=newNode->right=NULL;
	if(!*root){
		*root=newNode;
		return root;
	}
	if((*root)->data<a){
			insertInBSTInt(&((*root)->right),a);
	}
	else{
		insertInBSTInt(&((*root)->left),a);
	}
	return root;
}

void inOrderTraversalInt(struct BTNodeInt *root){
	if(!root)
		return;
	inOrderTraversalInt(root->left);
		printf("%d ",root->data);
	inOrderTraversalInt(root->right);
	
}
void preOrderTraversalInt(struct BTNodeInt *root){
	if(!root)
		return;
	printf("%d ",root->data);
	preOrderTraversalInt(root->left);
	preOrderTraversalInt(root->right);
	
}
void postOrderTraversalInt(struct BTNodeInt *root){
	if(!root)
		return;
	postOrderTraversalInt(root->left);
	postOrderTraversalInt(root->right);
	printf("%d ",root->data);
}
void levelOrderTraversalInt(struct BTNodeInt *root){
		
}

struct BTNodeInt* maxNodeInt(struct BTNodeInt *root){
	if(!root)
		return NULL;
	if(!root->right)
		return root;
	else return maxNodeInt(root->right);
	
}
struct BTNodeInt* minNodeInt(struct BTNodeInt *root){
	if(!root)
		return NULL;
	if(!root)return NULL;
	if(!root->left)
		return root;
	else return minNodeInt(root->left);
	
}
struct BTNodeInt* minNodeInorderIntSuccessor(struct BTNodeInt *root){
	
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
struct BTNodeInt* maxNodeInorderIntPredecessor(struct BTNodeInt *root){
	
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

struct BTNodeInt* findNodeInt(struct BTNodeInt* bst,int data){
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
struct BTNodeInt* findNodeParentInt(struct BTNodeInt* bst,int data){
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
struct BTNodeInt* findNodeInorderIntPredecessor(struct BTNodeInt* bst,int data){
	
	static struct BTNodeInt * par=NULL;
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
struct BTNodeInt* findNodeInorderIntSuccessor(struct BTNodeInt* bst,int data){
	static struct BTNodeInt *par=NULL;
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


