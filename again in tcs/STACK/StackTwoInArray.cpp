#include<iostream>
#include<stdlib.h>
using namespace std;
class TwoStacks{
	int *arr;
	int top1;
	int top2;
	int size;
	public:
		TwoStacks(int size){
			this->size=size;
			arr=new int[size];
			top1=-1;
			top2=size;
		}
		void push1(int x){
			if(top2>top1+1){
				top1++;
				arr[top1]=x;
			}
			else{
				cout << "\nOverflow: stack is Full"  << endl;
			
			}
		}
		void push2(int x){
			if(top1 < top2-1){
				top2--;
				arr[top2]=x;
			}else{
				cout << "Overflow: stack is full" << endl;
			}
		}
		int pop1(){
			if(top1==-1){
				cout << "Underflow: no element in stack" << endl;
				exit(1);
			}else{
				return arr[top1--];
			}
		}
		int pop2(){
			if(top2==size){
				cout << "Underflow: no element in stack" << endl;
				exit(1);
			}else{
				return arr[top2++];
			}
		}
};
int main(){
	 TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
	return 0;
}
