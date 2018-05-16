#include<stdio.h>
#include<string.h>
#include<malloc.h>
int partitionQuickSortInt(int *a,int p,int r){
	int i=p-1,j;
	int temp,pivot=a[r];
	for(i=p-1,j=p;j<r;j++)
	{
		if(a[j]<=pivot)
		{
		  i++;
		  temp=a[i];
		  a[i]=a[j];
		  a[j]=temp;

		}
	}
	i++;
	temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	return i;
}
void quickSortInt(int *ar,int p,int r){
	int q;
	if(p<r){
		q=partitionQuickSortInt(ar,p,r);
		quickSortInt(ar,p,q-1);
		quickSortInt(ar,q+1,r);
	}
}

int main(){
	int testCase,n,m,ring,flag,join,left,right;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d%d",&n,&m);
		join=0;
		int ar[m];
		left=0,right=m-1;
		flag=1;
		for (int i = 0; i <m ; i++)
		{
			scanf("%d",&ring);
			ar[i]=ring;
			if(ring!=1)
				flag=0;
		}
		if(flag==0)
		quickSortInt(ar,left,right);
		while(left!=right){
			ar[left]--;
			ar[right-1]+=ar[right]+1;
			right--;
			if(ar[left]==0)
				left++;
			join++;
		}
		printf("%d\n",join);
	}
	return 0;
}
