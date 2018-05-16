class LinkedList{
	private int data;
	private LinkedList next;
	public LinkedList(){
		
		this.next=null;
	
	}
	public LinkedList(int a[]){
	LinkedList temp1;
	LinkedList current=this;
	current.setData(a[0]);
	for(int i=1;i<a.length;i++){
		temp1=new LinkedList();
		temp1.setData(a[i]);
		current.setNext(temp1);
		current=temp1;
		}
	
	}
	public void setData(int data){
	
		this.data=data;
	}
	public int getData(){
		return this.data; 
	}
	public void setNext(LinkedList next){
		this.next=next;
	}
	public LinkedList getNext(){
		return this.next;
	}

}

