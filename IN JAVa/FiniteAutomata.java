class FiniteAutomata{
	char state[];
	int F[];
	public FiniteAutomata(String P){
			state=P.toCharArray();
			F=new int[P.length()];
			prefixTable(P);
	}
	private void prefixTable(String P){
		int i=1,j=0;
		F[0]=0;
		while(i<P.length()){
			if(P.charAt(i)==P.charAt(j)){
				F[i]=j+1;
				i++;
				j++;
			}
			else if(j>0)
				j=F[j-1];
			else{
				F[i]=0;
				i++;
			}
		}
	}
	public FiniteAutomata(){
	}
	
	public boolean finiteAutomataStringMatcher(String T){
					
		if(state==null||state.length<=0) {
			System.out.println("Pattern is undefined!");
		return false;
		}
		return finiteAutomataStringMatcher(new String(state),T);
	}
	
	
	public boolean finiteAutomataStringMatcher(String P,String T){
				state=P.toCharArray();
				F=new int[P.length()];
				prefixTable(P);
				
				
				if(state==null||state.length<=0) {
					System.out.println("Pattern is undefined!");
					return false;
					}
				int q=0;
				for(int i=0;i<T.length();i++)
				{	q=transition(q,T.charAt(i));
					if(q==state.length)
						return true;
				}
				return false;
	}
	
	public int transition(int q,char t){
		if(state[q]==t){
			return q+1;
			}
		else if(q>0){
			return F[q-1];
			}
		else return 0;
		
	}
	 
	 
	 
	 
	 
	
}
