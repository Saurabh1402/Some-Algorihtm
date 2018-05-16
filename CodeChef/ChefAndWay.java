import java.util.Scanner;

class ChefAndWay{
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int k=in.nextInt();
		int a[]=new int[n];
		int temp,b[]=new int[n];
		for(int i=0;i<n;i++){
			a[i]=in.nextInt();
		}
		for(int i=0;i<n;i++){
			b[i]=100000;
		}
		b[0]=a[0];
		b[1]=a[0]*a[1];
		for(int i=2;i<n;i++){
			for(int j=1;j<=k &&i-j>=0;j++){
				b[i]=min(b[i],a[i]*b[i-j]);
					 b[i]=b[i]%1000000007;
			}
			b[i]=b[i]%1000000007;
			
		}
		System.out.println(b[n-1]);
	}
	public static int min(int a,int b){
		return a>b?b:a;
	}
}
