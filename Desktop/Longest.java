public class Longest{
	static int[][] LongestPallidromeSubsequence(char c[],int size){
		int L[][]=new int[size][size],max=1,k;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size;j++)
			{
				L[i][j]=0;
			}
		}
		L[0][0]=1;
		for (int i = 1; i <size ; i++)
		{
			L[i][i]=1;
			if(c[i]==c[i-1]){
				L[i-1][i]=2;
				max=2;
			}
			else
				L[i-1][i]=0;
		}
		
		for (int i = 2; i <=size; i++)
		{
			for (int j = 0; j <size-i+1; j++)
			{
				k=j+i-1;
				if(c[j]==c[k]){
					L[j][k]=2+L[j+1][k-1];
					if(max<L[j][k]){
						max=L[j][k];
					}
				}
				else{
					L[j][k]=MAX(L[j+1][k],L[j][k-1]);
				}
			}
			
		}
		
		return L;
	}
	
	static int MAX(int a,int b){
		return a>b?a:b;
	}
	public static void main(String arg[]){
		String s="asdfghjkllkjhgfdsa";
		char c[]=s.toCharArray();
		int L[][]=LongestPallidromeSubsequence(c,c.length);
		for (int i = 0; i <s.length() ; i++)
		{
			for (int j = 0; j < s.length(); j++)
			{
				System.out.print(L[i][j]+" ");
			}
			System.out.println();
		}
		//for (int i = 0; i <c.length ; i++)
		//{
			//printf(c[i]+"");
		//}
		
		backtrack(c,L,0,s.length()-1,"");
	}
	static void backtrack(char A[],int L[][],int i,int j,String S){
		if(L[i][j]<=1) {
			System.out.println(""+S+S.substring(0,S.length()-1));
			return ;} 
		int a=j,b=i;
		//while(L[i][a]==L[i][a-1] && a>0 && a > i){
			//a--;
		//}
		while(L[b][j]==L[b+1][j] && b < L[i].length ){
			System.out.print(" "+L[b][j] );
			b++;
		}
		while(L[b][a]==L[b][a-1] && a>0 && a > b){
			a--;
		}
		
		printf("A;\n");
		backtrack(A,L,b-1,a-1,S+A[a]);
		
	}
	static void printf(String... S){
		for (int i = 0; i <S.length ; i++)
		{
			System.out.print(S[i]);
		}
	}
}
