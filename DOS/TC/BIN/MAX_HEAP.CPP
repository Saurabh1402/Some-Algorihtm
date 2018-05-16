#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
struct Heap* createHeap(int,int);
int parent(struct Heap*,int);
int leftChild(struct Heap*,int);
int rightChild(struct Heap* ,int);
int getMaximum(struct Heap* h);
int deleteMax(struct Heap* h);
void perlocateDown(struct Heap *,int);
void insertInHeap(struct Heap*,int);
void resizeHeapSize(struct Heap *);
struct Heap{
	int *array;
	int count;
	int capacity;
	int heap_type;
};
void main(){
struct Heap* h=createHeap(100,1);
int i,a[]={13,543,23,545,342,454,123,53,65,767,453,34};
clrscr();
for(i=0;i<12;i++){
	insertInHeap(h,a[i]);
}
for(i=0;i<h->count;i++){
printf("%d\t",h->array[i]);
}
getch();

}
struct Heap* createHeap(int capacity,int heap_type){
	struct Heap* h=(struct Heap*)malloc(sizeof(struct Heap));
	if(h==NULL){
		printf("Memory Error: line: 14");
		return NULL;
	}
	h->count=0;
	h->capacity=capacity;
	h->heap_type=heap_type;
	h->array=(int *)malloc(sizeof(int)*capacity);
	if(h->array==NULL){
		printf("Memory Error: line: 14");
		return NULL;
	}
	return h;
}
int parent(struct Heap *h,int c){
	int p=(c-1)/2;
	if(p<0||c<=0||c>=h->count)
		return -1;
	return p;

}
int leftChild(struct Heap *h,int p){
	int c=p*2+1;
	if(h->capacity<=c)
		return -1;
	return c;

}
int rightChild(struct Heap* h,int p){
	int c=2*p+2;
	if(h->capacity<=c){
		return -1;
	}
	return c;
	}
int getMaximum(struct Heap *h){
	if(h==NULL){
		printf("line:42	|  NULL EXCEPTION");
		return -1;
	}
	if(h->count==0){
	printf("line: 46 |  No Element");
	return -1;
	}
	return h->array[0];
}

int deleteMax(struct Heap *h){
	int data;
	if(h==NULL){
		printf("line: 54 |  NULL Exception");
		return -1;
	}

	if(h->count==0){
		printf("line : 59|    	No Element");
		return -1;
	}
	data=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	perlocateDown(h,0);
	return data;
}
void perlocateDown(struct Heap *h,int index){
int l,r,max=-1,temp;
l=leftChild(h,index);
r=rightChild(h,index);
	if(l!=-1 && h->array[index] < h->array[l]){
		max=l;
	}
	else{
	max=index;
	}
	if(r!=-1 && h->array[max] < h->array[r]){
		max=r;
	}
	if(max!=index){
		temp=h->array[index];
		h->array[index]=h->array[max];
		h->array[max]=temp;
		perlocateDown(h,max);
	}

}

void insertInHeap(struct Heap *h,int data){
	int i;
	if(h->count==h->capacity){
		resizeHeapSize(h);
	}
	h->count++;
	i=h->count-1;
	h->array[i]=data;
	while(i>0 && data > h->array[(i-1)/2]){
	     h->array[i]=h->array[(i-1)/2];
	     i=(i-1)/2;
	}
	h->array[i]=data;

}
void resizeHeapSize(struct Heap *h){
	int i,new_capacity,old_capacity;
	int *array=h->array;
	old_capacity=h->capacity;
	new_capacity=old_capacity*2;
	h->array=(int *)malloc(sizeof(int)*new_capacity);
	for(i=0;i<old_capacity;i++)
		h->array[i]=array[i];
	h->capacity=new_capacity;
	free(array);
}
