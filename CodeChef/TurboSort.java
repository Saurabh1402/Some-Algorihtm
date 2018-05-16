import java.util.Scanner;
class TurboSort{
		static void counting_sort(int A[],int n,int B[],int k){
		int C[]=new int[k+1],i;
		for (i = 0; i < n; i++)
		{	B[i]=-1;
			C[A[i]]++;
		}
		for (i = 1; i <=k ; i++)
		{
			C[i]+=C[i-1];
			C[i-1]--;
		}
		C[k]--;
		for (i = n-1; i >=0 ; i--)
		{
			B[C[A[i]]]=A[i];
			C[A[i]]--;
		}
		for (i = 0; i <n ; i++)
		{
			System.out.println(B[i]);
		}
}
public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int num,max=-1;
		num=in.nextInt();
		int A[]=new int[num];
		for (int i = 0; i <num ; i++)
		{
			A[i]=in.nextInt();
			if(A[i]>max)
				max=A[i];
		}
		in.close();
		int B[]=new int[num];
		counting_sort(A,num,B,max);
		
	}

}
