class TSTNode{
	private char data;
	private static char word[]=new char[1024];
	private boolean is_End_Of_String=false;
	private TSTNode left,eq,right;
	
	public static TSTNode insertInTST(TSTNode root,String S){
		if(root==null){
			root=new TSTNode();
			root.data=S.charAt(0);
			root.left=root.right=root.eq=null;
			
		}
		//System.out.println("S:  "+root.data+"\t");
		if((int)S.charAt(0)>(int)root.data)
			{
				root.right=insertInTST(root.right,S);
			}
		else if((int)S.charAt(0)<(int)root.data)
			{
				root.left=insertInTST(root.left,S);
			}
		else if((int)S.charAt(0)==(int)root.data)
		{
			if(S.length()>1){
				root.eq=insertInTST(root.eq,S.substring(1,S.length()));
				}
			else root.is_End_Of_String=true;
		}
		
		
			return root;
	}
	public static boolean searchTSTRecursive(TSTNode root,String S){
		if(root==null) return false;
		
		if((int)root.data>(int)S.charAt(0)){
				return searchTSTRecursive(root.left,S);
			}
		else if((int)root.data<(int)S.charAt(0)){
				return searchTSTRecursive(root.right,S);
			}
		else if((int)root.data==(int)S.charAt(0)){
			
				
			if(root.is_End_Of_String && S.length()==1){
				return true;
				}
			else{
				return searchTSTRecursive(root.eq,S.substring(1,S.length()));
			}
				
		}
		
			return false;
		}
	public static void DisplayAllTST(TSTNode root,int count){
		if(root==null){
			return;
			}
		DisplayAllTST(root.left,count);
		word[count]=root.data;
		
		if(root.is_End_Of_String==true){
			System.out.println(new String(word,0,count+1));
		}
		DisplayAllTST(root.eq,count+1);
		DisplayAllTST(root.right,count);
	}
}
