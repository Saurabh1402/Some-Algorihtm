struct Heap{
	int capacity,count;
	int *array;
	int heap_type;
	}
struct Heap*  createIntHeap(int capacity,int heap_type){
	struct Heap *h=(struct Heap)malloc(sizeof(struct Heap));
	if(h==NULL){
		printf("Out Of Memory!");
		return;
		}
	h->count=0;
	h->capacity=capacity;
	h->heap_type=heap_type;
	h->array=(int *)malloc(sizeof(int)*h->capacity);
	if(h->array==NULL){
		printf("Out of Memory");
		return;
		}
	return h;
	}
int ParentIntHeap(struct Heap *h,int child){
	if(child<=0||child>=h->count)
	return (child-1)/2;
	
	}
int LeftChildIntHeap(struct Heap *h,int p){
	int c=p*2+1;
	if(c>=h->count){
		return -1;
		}
	else return c;
}
int RightChildIntHeap(struct Heap *h,int p){
	int c=p*2+2;
	if(c>=h->count){
		return -1;
		}
	else return c;
}
int getMaximumIntHeap(struct Heap *h){
	if(h->count<=0){
		return -1;
		}
		return h->array[0];
	}
void percolateDownIntHeap(struct Heap *h,int i){
	
	int l,r,max=i,temp;
	l=LeftChildIntHeap(h,i);
	r=RightChildIntHeap(h,i);
	if(l!=-1 && h->array[l] > h->array[i]){
		max=l;
	}
	if(r!=-1 && h->array[r] > h->array[max]){
		max=r;
		}
	if(max!=i){
		temp=h->array[max];
		h->array[max]=h->array[i];
		h->array[i]=temp;
		
		percolateDownIntHeap(h,max);				//wrong in Book page 197
		}
	
}
int DeleteMaxIntHeap(struct Heap *h){
	int data;
	if(h->count<=0) return -1;
	data=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count=h->count-1;
	percolateDownIntHeap(h,0);
	return data;
}

int insertIntHeap(struct Heap *h,int data){
	int i;
	if(h->count==h->capacity)
		ResizeHeapIntHeap(h);
	h->count++;
	i=h->count -1;
	while(i>=0&&data>h->array[(i-1)/2]){
		h->array[i]=h->array[(i-1)/2];
		i=(i-1)/2
	}
	h->array[i]=data;
}
void resizeHeapIntHeap(struct Heap *h){
	int i,capacity=h->capacity*2;
	int *array=h->array;
	h->array=(int *)malloc(sizeof(int)*capacity);
	for(i=0;i<h->capacity;i++){
		h->array[i]=array[i];
	}
	h->capacity=capacity;
	free(array);
	}
