class ReverseXOR{
	public static String reverseString(String str){
		
		char rev[]=str.toCharArray();
		int start=0,end=rev.length-1;
		
		for(;start<end;start++,end--){
		rev[start]^=rev[end];
		rev[end]^=rev[start];
		rev[start]^=rev[end];
		
	}
	return new String(rev);
	}
	public static char[] reverseCharArray(char rev[]){
	
		int start=0,end=rev.length-1;
		
		for(;start<end;start++,end--){
		rev[start]^=rev[end];
		rev[end]^=rev[start];
		rev[start]^=rev[end];
		
	}
	return rev;
	}
	public static int[] reverseIntArray(int rev[]){
	
		int start=0,end=rev.length-1;
		
		for(;start<end;start++,end--){
		rev[start]^=rev[end];
		rev[end]^=rev[start];
		rev[start]^=rev[end];
		
	}
	return rev;
	}

}
