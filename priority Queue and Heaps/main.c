#include "maxHeap.H"
int main(){
			struct IntMaxHeap* h=createHeapIntMaxHeap(1,1);
			int i,a[]={13,543,23,545,342,454,123,53,65,767,453,34};
			for(i=0;i<12;i++){
				insertInHeapIntMaxHeap(h,a[i]);
			}
			for(i=0;i<h->count;i++){
			printf("%d\t",h->array[i]);
			}
			for(i=0;i<h->count;i++){
			printf("%d\t",h->array[i]);
			}
			return 0;
		}
