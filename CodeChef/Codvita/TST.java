import java.util.Scanner;
import java.io.*;
class TST{
		public static void main(String args[]) throws IOException{
				int testCase;
				BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
				testCase=Integer.parseInt(br.readLine());
				while(testCase-->0){
					String s=br.readLine();
					String ch[]=s.split(" ");
					int count=Integer.parseInt(br.readLine());
					for (int i = 0; i <ch.length ; i+=2){
						ch[i]=ch[i].toLowerCase();
					}
					
					for (int i = 0; i <count ; i++)
					{	int temp=i;
						if(i%2==0){
							
							for (int j = i+2; j < ch.length; j+=2)
							{
								if(ch[temp].compareTo(ch[j])>0)
								temp=j;
							}
							
						}
						else{
							for (int j = i+2; j < ch.length; j+=2)
							{
								if(Integer.parseInt(ch[temp])>Integer.parseInt(ch[j]))
									temp=j;
							}
							
						}
						String te1;
						te1=ch[temp];
						ch[temp]=ch[i];
						ch[i]=te1;
					}
					for (int i = 0; i <ch.length ; i++)
					{
						System.out.print(ch[i]+" ");
					}
					
					
				}
				
		}
}
