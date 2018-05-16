import java.util.Scanner;
class CAX{
	public static void main(String args[]){
	int testCase;
	int no,min,temp,temp1;
	Scanner in=new Scanner(System.in);
	testCase=in.nextInt();
	while(testCase--!=0){
		no=in.nextInt();
		temp=min=no;
		temp1=temp+1;
		while(temp!=0){
			if(temp^temp1==no){
				min=no;
			}
			temp1--;
			temp--;
		}
		if(min!=no)
		System.out.println(min);
		else
			System.out.println("-1");
		
	}

	}
}
