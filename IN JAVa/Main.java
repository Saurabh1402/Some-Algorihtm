class Main{
	public static void main(String s[]){
		//System.out.println("Hello World");
		int a[]={34,2421,1,656,53,67,8,88,77,77,565};
		
		// 	Linked List
		/*
		  LinkedList l=new LinkedList(a);
			while(l!=null){
			System.out.print(l.getData()+"->");
			l=l.getNext();
			}
		*/
		
		
		
		
		
		//	QuickSort
		/*
		 QuickSort sort=new QuickSort();
		a=sort.execute(a); 
		if(a!=null)
			for(int i=0;i<a.length;i++){
				System.out.print(a[i]+" -> ");
			}
		*/
		
		
		
		
		
		//	FiniteAutomata
		
		/*
		FiniteAutomata fa=new FiniteAutomata();
		if(fa.finiteAutomataStringMatcher("Saurbh","SfdsfgfdgsdfSaurbhFdsfsSardfafaf"))
			System.out.println("True");
		else
		{
			System.out.println("False");
		
		}
		 
		 */
		
		
		
		
		
		//Ternary Search Trees NON-OOP
				TSTNode tst=null;
				tst=TSTNode.insertInTST(tst,"Saurabh");
				tst=TSTNode.insertInTST(tst,"Vishwka");
				
				tst=TSTNode.insertInTST(tst,"Aayush");
				tst=TSTNode.insertInTST(tst,"Vijayvergiya");
				
				tst=TSTNode.insertInTST(tst,"Saumya");
				tst=TSTNode.insertInTST(tst,"Saurabh Vishwakarma");
				TSTNode.DisplayAllTST(tst,0);

		
		
		//Tree Search Trees OOP
		/*
				TSTNodeOOP t=new TSTNodeOOP();
				t.insertInTSTOOP("Saurabh");
				t.insertInTSTOOP("Vishwakarma");
				t.insertInTSTOOP("Saumya");
				t.insertInTSTOOP("Aayush");
				t.insertInTSTOOP("Vijayvergiya");
				t.insertInTSTOOP("Yogesh");
				t.insertInTSTOOP("Sunny");
				if(t.searchTSTRecursiveOOP("Saurabh"))
					System.out.println("S:  True");
				else System.out.println("S:  false");
				if(t.searchTSTRecursiveOOP("Vishwakarmaaaa"))
					System.out.println("S:  True");
				else System.out.println("S:  false");
				if(t.searchTSTRecursiveOOP("Saumya"))
					System.out.println("S:  True");
				else System.out.println("S:  false");
				if(t.searchTSTRecursiveOOP("AayushVergiya"))
					System.out.println("S:  True");
				else System.out.println("S:  false");
				if(t.searchTSTRecursiveOOP("Sunny"))
					System.out.println("S:  True");
				else System.out.println("S:  false");
				
		
		*/
			
		
		//Reverse String And Char Array
		/*
		int str[]={51,52,53,54,55,56};
		System.out.println(ReverseXOR.reverseString("Saurabh"));
		System.out.println(new String(ReverseXOR.reverseCharArray(("Vishwakarma".toCharArray()))));	
		System.out.println(ReverseXOR.reverseIntArray(str)[0]);	
		
		*/
		
	}
		
			
}
