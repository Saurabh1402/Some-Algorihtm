import java.util.Scanner;
class ImageSeg{
	int count[][];
	public static void main(String args[]){
		int testCase;
		int width,height;
		Scanner in=new Scanner(System.in);
		testCase=in.nextInt();
		while(testCase-->0){
			height=in.nextInt();
			width=in.nextInt();
			char ch[][]=new char[height][width];
			ch[][]=new int[height][width];
			for (int i = 0; i < height; i++){
				String s=in.next();
				ch[i]=s.toCharArray();
			}
			for (int i = width; i <=1 ; i--)
			{
				check(ch,0,0,i,count);
			}
			
			
		}
	}
}

