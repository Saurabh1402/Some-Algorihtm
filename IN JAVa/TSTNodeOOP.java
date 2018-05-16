class TSTNodeOOP{
	private char data;
	private boolean is_End_Of_String=false;
	private TSTNodeOOP left,right,eq;
	
	public char getData(){
		return data;
		}
	public void setData(char data){
		this.data=data;
		}
	public void setEndOfString(boolean b){
		this.is_End_Of_String=b;
		}
	public boolean getEndOfString(){
		return is_End_Of_String;
		}
	public TSTNodeOOP getLeft(){
		return left;
		}
	public void setLeft(TSTNodeOOP left){
		this.left=left;
		}
	public TSTNodeOOP getRight(){
		return right;
		}
	public void setRight(TSTNodeOOP right){
		this.right=right;
		}
		public TSTNodeOOP getEqual(){
		return eq;
		}
	public void setEqual(TSTNodeOOP eq){
		this.eq=eq;
		}
	

	public TSTNodeOOP insertInTSTOOP(String S){
		
		if(this.getData()=='\0'){
			this.setData(S.charAt(0));
			this.left=this.right=this.eq=null;	
			}
		if((int)this.getData()>S.charAt(0)){
			if(this.getLeft()==null)
				this.setLeft(new TSTNodeOOP());
			this.getLeft().insertInTSTOOP(S);
			
		} else if((int)this.getData()<S.charAt(0)){
			if(this.getRight()==null)
				this.setRight(new TSTNodeOOP());
			this.getRight().insertInTSTOOP(S);
		} else if((int)this.getData()==S.charAt(0)){
			
			if(S.length()>1){
				if(this.getEqual()==null)
					this.setEqual(new TSTNodeOOP());
				this.getEqual().insertInTSTOOP(S.substring(1,S.length())) ;
				}
			else{
				
					this.setEndOfString(true);
				
				}
			
			}
		
		return this;
	}
	
	public boolean searchTSTRecursiveOOP(String S){
		if(this.getData()>S.charAt(0)){
			if(this.getLeft()!=null)
				return this.getLeft().searchTSTRecursiveOOP(S);
			else return false;
		}else if(this.getData()<S.charAt(0)){
			if(this.getRight()!=null)
				return this.getRight().searchTSTRecursiveOOP(S);
			else return false;
		}
		else if(this.getData()==S.charAt(0)){
			if(this.getEndOfString() && S.length()==1){
				return true;
			}
			else{
				if(S.length()>1&&this.getEqual()!=null){
					return this.getEqual().searchTSTRecursiveOOP(S.substring(1,S.length()));
				
			}else return false;
			}
		}
		
		return false;
	}

	
}
