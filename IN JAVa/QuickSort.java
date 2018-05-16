class QuickSort{
	int a[];
	public QuickSort(int a[]){
		this.a=a;
	}
	public QuickSort(){
		
	}
	public int[] execute(){
			if(a==null)return null;
			sort(0,a.length-1);
			return a;
			
	}
	public int[] execute(int b[]){
			if(b!=null) this.a=b;
			if(a==null)return null;
			sort(0,a.length-1);
			return a;
			
	}
	
	private void sort(int p,int r){
		
		if(p<r){
			int q=partition(p,r);
			this.sort(p,q-1);
			this.sort(q+1,r);
			}
		
	}
	private int partition(int p,int r){
			
			int x=a[r];
			int j,i=p-1;
			for(j=p;j<r;j++){
				if(a[j]<=x){
					i++;
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					
				}
			}
					i++;
					int temp=a[i];
					a[i]=a[r];
					a[r]=temp;
			return i;
		
		}
		
		
	}
