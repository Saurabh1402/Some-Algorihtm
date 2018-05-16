import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{	int temp;
		String s="";
		Scanner in=new Scanner(System.in);
		while(true)
		{
			temp=in.nextInt();
			if(temp!=42){
				s+=temp+"\n";
			}
			else{
				System.out.print(s);
				break;
			}
		
		}
	}
}
