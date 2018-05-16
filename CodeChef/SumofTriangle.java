import java.util.Scanner;
class SumofTriangle{
	public static void main(String args[]){
	int testCase;
	int size;
	Scanner in=new Scanner(System.in);
	testCase=in.nextInt();
	int ans[]=new int[testCase],max,temp;
	for (int i = 0; i <testCase; i++)
	{	ans[i]=0;
		size=in.nextInt();
		int ar[][]=new int[size][];
		for (int j = 0; j < size; j++)
		{
			ar[j]=new int[j+1];
			for (int k = 0; k < j+1; k++)
			{
				ar[j][k]=0;
			}
			
		}
		max=-1;
		for (int j = 0; j <size ; j++)
		{	
			for (int k = 0; k <=j ; k++)
			{
				ar[j][k]=in.nextInt();
				if(k==0){
					if(j!=0){
						ar[j][k]+=ar[j-1][k];
					}
				}
				else if(k==j){
					ar[j][k]+=ar[j-1][k-1];
				}
				else{
					if(ar[j-1][k-1]>ar[j-1][k]){
						ar[j][k]+=ar[j-1][k-1];
					}
					else{
						ar[j][k]+=ar[j-1][k];
					}
				}
				if(j==size-1){
					if(ar[j][k]>max)
						max=ar[j][k];
				}
			}
		}
		ans[i]=max;
		
		
	}
	for (int i = 0; i < testCase; i++)
	{
		
		System.out.println(ans[i]);
	}
	
	
	
		
	}
}
