#include<stdio.h>
#include<alloc.h>
#include<conio.h>
struct BSTNodeInt** insertInBSTInt(struct BSTNodeInt**,int );
void inorderTravesalInt(struct BSTNodeInt *);
struct BSTNodeInt* maxNodeInt(struct BSTNodeInt *);
struct BSTNodeInt* minNodeInt(struct BSTNodeInt *);
struct BSTNodeInt* maxNodeInorderIntPredecessor(struct BSTNodeInt *);
struct BSTNodeInt* minNodeInorderIntSuccessor(struct BSTNodeInt *);

struct BSTNodeInt* findNodeInt(struct BSTNodeInt*,int );
struct BSTNodeInt* findNodeParentInt(struct BSTNodeInt*,int );
struct BSTNodeInt* findNodeInorderIntPredecessor(struct BSTNodeInt* ,int);
struct BSTNodeInt* findNodeInorderIntSuccessor(struct BSTNodeInt* ,int);


struct BSTNodeInt{
	int data;
	struct BSTNodeInt *left;
	struct BSTNodeInt *right;
};

		int main(){
			int i,a[]={34,26,17,2432,78,56,45,11,45,23,167,981,1};
			int find=17;
			struct BSTNodeInt *root=NULL;
			for(i=0;i<13;i++)
				insertInBSTInt(&root,a[i]);
			inorderTravesalInt(root);
			minNodeInorderIntSuccessor(root);
			maxNodeInorderIntPredecessor(root);
			printf("\n");
			findNodeInorderIntSuccessor(root,26);
			if(findNodeInt(root,2432)!=NULL)printf("\nFind Node:	%d",findNodeInt(root,2432)->data);
			if(findNodeParentInt(root,find)!=NULL)printf("\nParent of %d:	%d",find,findNodeParentInt(root,find)->data);
			getch();
			return 0;
}

struct BSTNodeInt** insertInBSTInt(struct BSTNodeInt **root,int a){
	struct BSTNodeInt *newNode=(struct BSTNodeInt *)malloc(sizeof(struct BSTNodeInt));
	newNode->data=a;
	newNode->left=newNode->right=NULL;
	if(!*root){
		*root=newNode;
		return root;
	}
	if((*root)->data<a){
			insertInBSTInt(&((*root)->right),a);
	}
	else if((*root)->data > a ){
		insertInBSTInt(&((*root)->left),a);
	}
	return root;
}

void inorderTravesalInt(struct BSTNodeInt *root){
	if(!root)
		return;
	inorderTravesalInt(root->left);
		printf("%d ",root->data);
	inorderTravesalInt(root->right);
	
}
struct BSTNodeInt* maxNodeInt(struct BSTNodeInt *root){
	if(!root)
		return NULL;
	if(!root->right)
		return root;
	else return maxNodeInt(root->right);
	
}
struct BSTNodeInt* minNodeInt(struct BSTNodeInt *root){
	if(!root)
		return NULL;
	if(!root)return NULL;
	if(!root->left)
		return root;
	else return minNodeInt(root->left);
	
}
struct BSTNodeInt* minNodeInorderIntSuccessor(struct BSTNodeInt *root){
	
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
struct BSTNodeInt* maxNodeInorderIntPredecessor(struct BSTNodeInt *root){
	
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

struct BSTNodeInt* findNodeInt(struct BSTNodeInt* bst,int data){
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
struct BSTNodeInt* findNodeParentInt(struct BSTNodeInt* bst,int data){
		
		if(bst->data==data){
			printf("Data Found But Root Node...No Parent!:  %d",data);
				return NULL;}
		if(bst==NULL||(bst->data > data && bst->left==NULL)||(bst->data < data && bst->right==NULL)){
			printf("Not Found! %d",data);
			return NULL;
		}
		if(bst->left->data==data||bst->right->data==data){
			return bst;
		}
		if(bst->data<data) return findNodeParentInt(bst->right,data);
		else return findNodeParentInt(bst->left,data); 

}
struct BSTNodeInt* findNodeInorderIntPredecessor(struct BSTNodeInt* bst,int data){
	
	static struct BSTNodeInt * par=NULL;
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
struct BSTNodeInt* findNodeInorderIntSuccessor(struct BSTNodeInt* bst,int data){
	static struct BSTNodeInt *par=NULL;
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


