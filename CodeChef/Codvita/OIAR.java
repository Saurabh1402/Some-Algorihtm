import java.util.Scanner;
class OIAR{
	public static void main(String args[]){
		int testCase;
		int lb,ub;
		String s;
		Scanner in=new Scanner(System.in);
	testCase=in.nextInt();
	lb=in.nextInt();
	ub=in.nextInt();
	int no_length=0;
	while(testCase-->0){
		s=in.next();
		if(s.charAt(0)=='A'){
			String temp=s.substring(1,s.length());
			int temp1=Integer.parseInt(temp);
			int count=0;
			boolean flag=true;
			for (int i = lb; i <=ub; i++)
			{	int temp3=10,temp2=i;
				flag=true;
				int c_c;
				if(temp2%10==temp1){
					c_c=0;
					while(temp2!=0){
						if(temp2%temp3!=temp1){
							flag=false;
							break;
						}else{
							c_c++;
							temp2/=100;
							
						}
					}
				}
				else if(temp2%100==temp1){
						c_c=0;
						while(temp2!=0){
							if(temp2%temp3!=temp1){
								flag=false;
								break;
							}else{
								c_c++;
								temp2/=100;
							}
						}
				}
				else{
					continue; 
				}
				if(flag=true&& c_c>1)
					count++;
			}
			System.out.println(count);
		}
		else if(s.charAt(0)=='C'){
			int freq=Integer.parseInt(s.charAt(1)+"");
			int digit=Integer.parseInt(s.charAt(2)+"");
			int count_2=0,flag=1;
			int temp_f;
			for (int i = 2; i <=200 ; i++)
			{
				String b="";
				for (int j = 0; j < freq; j++)
					b+=digit+"";
				
				if((i+"").contains(b))
				count_2++;
			}
			System.out.println(count_2);
		}
		else{
			char c[]=s.toCharArray();
			int arr[]=new int[c.length];
			System.out.println("100");
		}
	}
	}
}
