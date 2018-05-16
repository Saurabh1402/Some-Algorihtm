#include<stdio.h>
#include "SimLList.h"
#define LOAD_FACTOR 20

struct HashTable* createHashTable(int );
int hashInsert(struct HashTable *,int);
int hashIndex(int,int);
int hashSearch(struct HashTable*,int);
void displayHashTable(struct HashTable *);
struct HashTable* resizeHashTable(struct HashTable *);
struct HashTableNode{
	int bcount;
	struct SimpleLinkedListInt *next;
};
struct HashTable{
	int tsize;
	int count;
	struct HashTableNode **Table;
};

//int main(){
	//struct HashTable *h=NULL;
	//h=createHashTable(50);
	//hashInsert(h,10);
	//hashInsert(h,112);
	//hashInsert(h,110);
	//hashInsert(h,19);
	//hashInsert(h,1102);
	//hashInsert(h,101);
	//hashInsert(h,120);
	//printf("%d\n",h->tsize);
	//displayHashTable(h);
	//h=resizeHashTable(h);
	//printf("\n-------------------------------------------------\n");
	//displayHashTable(h);
	//printf("\n");
	//return 0;	
//}

struct HashTable * createHashTable(int size){
	struct HashTable *h=NULL;
	h=(struct HashTable*)malloc(sizeof(struct HashTable));
	if(!h){
		return NULL;
	}
	h->tsize=size/LOAD_FACTOR;
	h->count=0;
	h->Table=(struct HashTableNode**)malloc(sizeof(struct HashTableNode*)*h->tsize);
	if(!h->Table){
		printf("Line::23: Memory Error");
		return NULL;
	}
	for (int i = 0; i < h->tsize; i++){
		h->Table[i]=(struct HashTableNode*)malloc(sizeof(struct HashTableNode));
		if(!h->Table[i]){
			printf("Line::23: Memory Error");
			return NULL;
		}
	}
	
	for (int i = 0; i <h->tsize ; i++)
	{
		h->Table[i]->next=NULL;
		h->Table[i]->bcount=0;
	}
	return h;
}
int hashSearch(struct HashTable *h,int data){
	struct SimpleLinkedListInt *temp=NULL;
	int index=hashIndex(data,h->tsize);
	temp=h->Table[index]->next;
	while(temp!=NULL){
	if(temp->data==data)
		return 1;
	temp=temp->next;
	}
	return 0;
}
int hashInsert(struct HashTable *h,int data){
	
	int index;
	//struct SimpleLinkedListInt *temp=NULL,*newNode=NULL;
	if(hashSearch(h,data)){
		return 0;
	}
	index=hashIndex(data,h->tsize);
	h->Table[index]->next=insertAtBeginningSimpleLinkedListInt(&h->Table[index]->next,data,index);
	h->Table[index]->bcount++;
	h->count++;
	if(h->count/h->tsize> LOAD_FACTOR){
		resizeHashTable(h);
	}
	return 1;
}
int hashIndex(int data,int tsize){
		int index;
		index=data%tsize;
		return index;
}
int hashDelete(struct HashTable *h,int data){
	int index=0;
	index=hashIndex(data,h->tsize);
	if(deleteDataSimpleLinkdListInt(&h->Table[index]->next,data)!=-1){
		h->Table[index]->bcount--;
		h->count--;
		return 1;
	}
	return 0;
}
struct HashTable* resizeHashTable(struct HashTable *h){
	
	int oldsize,i,index;
	struct SimpleLinkedListInt *temp,*temp2;
	struct HashTableNode **oldTable;
	oldsize=h->tsize;
	oldTable=h->Table;
	h->tsize=h->tsize*2;
	h->Table=(struct HashTableNode **)malloc(h->tsize*sizeof(struct HashTableNode *));
	h->Table=(struct HashTableNode**)malloc(sizeof(struct HashTableNode*)*h->tsize);
	if(!h->Table){
		printf("Line::101: Memory Error");
		return NULL;
	}
	for (i = 0; i < h->tsize; i++){
		h->Table[i]=(struct HashTableNode*)malloc(sizeof(struct HashTableNode));
		if(!h->Table[i]){
			printf("Line::107: Memory Error");
			return NULL;
		}
	}
	
	for (i = 0; i <h->tsize; i++)
	{
		h->Table[i]->next=NULL;
		h->Table[i]->bcount=0;
	}
	for (i = 0; i < oldsize; i++)
	{
		for (temp=oldTable[i]->next;temp;)
		{
			index=hashIndex(temp->data,h->tsize);
			temp2=temp;
			temp=temp->next;
			temp2->next=h->Table[index]->next;
			h->Table[index]->next=temp2;
			h->Table[index]->bcount++;
		}
		free(oldTable[i]);
	}
	
	return h;
}
void displayHashTable(struct HashTable *h){
	int i;
	for (i = 0; i <h->tsize ; i++)
	{	if(h->Table[i]->bcount!=0){
		displaySimpleLinkedListInt(h->Table[i]->next);
		printf("\n");
		}
	}
}
