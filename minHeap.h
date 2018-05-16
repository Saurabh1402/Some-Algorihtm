#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct IntMinHeap* createHeapIntMinHeap(int,int);
int parentIntMinHeap(struct IntMinHeap*,int);
int leftChildIntMinHeap(struct IntMinHeap*,int);
int rightChildIntMinHeap(struct IntMinHeap* ,int);
int getMinIntMinHeap(struct IntMinHeap* h);
int deleteMinIntMinHeap(struct IntMinHeap* h);
void perlocateDownIntMinHeap(struct IntMinHeap *,int);
void insertInHeapIntMinHeap(struct IntMinHeap*,int);
void resizeHeapSizeIntMinHeap(struct IntMinHeap *);
struct IntMinHeap{
	int *array;
	int count;
	int capacity;
	int heap_type;
};
	/*
		int main(){
					struct IntMinHeap* h=createHeapIntMinHeap(100,1);
					int i,a[]={13,543,23,545,342,454,123,53,65,767,453,34};
					for(i=0;i<12;i++){
						insertInHeapIntMinHeap(h,a[i]);
					}
					for(i=0;i<h->count;i++){
					printf("%d ",h->array[i]);
					}printf("\n");
					printf("S: %d\n",deleteMinIntMinHeap(h));
					printf("S: %d\n",deleteMinIntMinHeap(h));
					printf("S: %d\n",deleteMinIntMinHeap(h));
					printf("S: %d\n",deleteMinIntMinHeap(h));
					printf("S: %d\n",deleteMinIntMinHeap(h));
					printf("S: %d\n",deleteMinIntMinHeap(h));
					printf("S: %d\n",deleteMinIntMinHeap(h));
					for(i=0;i<h->count;i++){
					printf("%d ",h->array[i]);
					}printf("\n");
					return 0;
		}
	*/

struct IntMinHeap* createHeapIntMinHeap(int capacity,int heap_type){
	struct IntMinHeap* h=(struct IntMinHeap*)malloc(sizeof(struct IntMinHeap));
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
int parentIntMinHeap(struct IntMinHeap *h,int c){
	int p=(c-1)/2;
	if(p<0||c<=0||c>=h->count)
		return -1;
	return p;

}
int leftChildIntMinHeap(struct IntMinHeap *h,int p){
	int c=p*2+1;
	if(h->count<=c)
		return -1;
	return c;

}
int rightChildIntMinHeap(struct IntMinHeap* h,int p){
	int c=2*p+2;
	if(h->count<=c){
		return -1;
	}
	return c;
	}
int getMinIntMinHeap(struct IntMinHeap *h){
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

int deleteMinIntMinHeap(struct IntMinHeap *h){
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
	perlocateDownIntMinHeap(h,0);
	return data;
}
void perlocateDownIntMinHeap(struct IntMinHeap *h,int index){
int l,r,min=-1,temp;
l=leftChildIntMinHeap(h,index);
r=rightChildIntMinHeap(h,index);
	if(l!=-1 && h->array[index] > h->array[l]){
		min=l;
	}
	else{
	min=index;
	}
	if(r!=-1 && h->array[min] > h->array[r]){
		min=r;
	}
	if(min!=index){
		temp=h->array[index];
		h->array[index]=h->array[min];
		h->array[min]=temp;
		
		perlocateDownIntMinHeap(h,min);
	}

}

void insertInHeapIntMinHeap(struct IntMinHeap *h,int data){
	int i;
	if(h->count==h->capacity){
		resizeHeapSizeIntMinHeap(h);
	}
	h->count++;
	i=h->count-1;
	h->array[i]=data;
	while(i>0 && data < h->array[(i-1)/2]){
	     h->array[i]=h->array[(i-1)/2];
	     i=(i-1)/2;
	}
	h->array[i]=data;

}
void resizeHeapSizeIntMinHeap(struct IntMinHeap *h){
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
