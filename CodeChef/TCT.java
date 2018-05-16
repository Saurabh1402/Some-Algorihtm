import java.util.Scanner;
class TCT{
	public static void main(String args[]){
		int testCase,counter=0,a[]=new int[26];
		Scanner in=new Scanner(System.in);
		testCase=in.nextInt();
		String s,ans="";
		char ch[];
		for (int i = 0; i < testCase; i++)
		{	a=new int[26];
			s=in.next();
			counter=0;
			ch=s.toCharArray();
			for (int j = 0; j <ch.length; j++)
			{	if(a[(int)ch[j]-97]==0){
					a[(int)ch[j]-97]++;
					counter++;
				}
			}
			if(counter%2==0){
				if(ans.equals(""))
					ans+="Terrorist";
				else
					ans+="\nTerrorist";
			}else{
				if(ans.equals(""))
					ans+="Counter Terrorist";
				else
					ans+="\nCounter Terrorist";
			}
			
			
		}
		System.out.println(ans);
	}
}
