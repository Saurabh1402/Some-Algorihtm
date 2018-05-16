#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct IntMaxHeap* createHeapIntMaxHeap(int,int);
int parentIntMaxHeap(struct IntMaxHeap*,int);
int leftChildIntMaxHeap(struct IntMaxHeap*,int);
int rightChildIntMaxHeap(struct IntMaxHeap* ,int);
int getMaximumIntMaxHeap(struct IntMaxHeap* h);
int deleteMaxIntMaxHeap(struct IntMaxHeap* h);
void perlocateDownIntMaxHeap(struct IntMaxHeap *,int);
void insertInHeapIntMaxHeap(struct IntMaxHeap*,int);
void resizeHeapSizeIntMaxHeap(struct IntMaxHeap *);
struct IntMaxHeap{
	int *array;
	int count;
	int capacity;
	int heap_type;
};
/*
		int main(){
			struct IntMaxHeap* h=createHeapIntMaxHeap(100,1);
			int i,a[]={13,543,23,545,342,454,123,53,65,767,453,34};
			for(i=0;i<12;i++){
				insertInHeapIntMaxHeap(h,a[i]);
			}
			for(i=0;i<h->count;i++){
			printf("%d\t",h->array[i]);
			}
			printf("\n%d\n",deleteMaxIntMaxHeap(h));
			printf("\n%d\n",deleteMaxIntMaxHeap(h));
			printf("\n%d\n",deleteMaxIntMaxHeap(h));
			printf("\n%d\n",deleteMaxIntMaxHeap(h));
			for(i=0;i<h->count;i++){
			printf("%d\t",h->array[i]);
			}
			return 0;
}
*/
struct IntMaxHeap* createHeapIntMaxHeap(int capacity,int heap_type){
	struct IntMaxHeap* h=(struct IntMaxHeap*)malloc(sizeof(struct IntMaxHeap));
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
int parentIntMaxHeap(struct IntMaxHeap *h,int c){
	int p=(c-1)/2;
	if(p<0||c<=0||c>=h->count)
		return -1;
	return p;

}
int leftChildIntMaxHeap(struct IntMaxHeap *h,int p){
	int c=p*2+1;
	if(h->count<=c)
		return -1;
	return c;

}
int rightChildIntMaxHeap(struct IntMaxHeap* h,int p){
	int c=2*p+2;
	if(h->count<=c){
		return -1;
	}
	return c;
	}
int getMaximumIntMaxHeap(struct IntMaxHeap *h){
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

int deleteMaxIntMaxHeap(struct IntMaxHeap *h){
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
	perlocateDownIntMaxHeap(h,0);
	return data;
}
void perlocateDownIntMaxHeap(struct IntMaxHeap *h,int index){
int l,r,max=-1,temp;
l=leftChildIntMaxHeap(h,index);
r=rightChildIntMaxHeap(h,index);
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
		perlocateDownIntMaxHeap(h,max);
	}

}

void insertInHeapIntMaxHeap(struct IntMaxHeap *h,int data){
	int i;
	if(h->count==h->capacity){
		resizeHeapSizeIntMaxHeap(h);
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
void resizeHeapSizeIntMaxHeap(struct IntMaxHeap *h){
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
