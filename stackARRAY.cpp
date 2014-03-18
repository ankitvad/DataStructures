//Stacks-LIFO
int const SIZE=20;
#include <iostream>
#include <stdlib.h>

using namespace std;

class stack
{
private:
	int array[SIZE];
	int top;
	int max;
public:
	stack()
	{
		top=-1;
		max=SIZE;
	};
	void push();
	void pop();
	void display();

};
void stack::push()
{
	if(top==max)
		cout<<"\n Sorry Overflow condition achieved";
	else
		top+=1;
		cout<<"\n Please enter the element to be pushed in the stack:";
	    cin>>array[top];
	    
	    cout<<"\n Element pushed in stack";
}
void stack::pop()
{
	if(top==1)
		cout<<"\n Sory underflow condition aceived:";
	else
		top-=1;
	cout<<"\n Element popped from the stack";

}
void stack::display()
{
	int i;
	cout<<"\n The element of the stack is:";
	for(i=top;i>=0;i--)
cout<<array[i]<<"\t";
}

int main()
{
	stack s1;
	int num;
	char choice;
	do
	{
			cout<<"\nPlease enter the number based on your choice.\n1.Push an element in the stack.\t2.Pop an element from the stack.\n3.View Stack.\t4.Exit";
            cin>>num;
            switch(num)
            {
            	case 1: s1.push();break;
            	case 2: s1.pop();break;
            	case 3: s1.display();break;
            	case 4: exit(0);break;
            	default: cout<<"\n Please enter the collect number from 1-4";

            }  
            cout<<"\nDo you wish to continue ? (y/n)";
            cin>>choice;
            

	}while(choice=='y'||choice=='Y');
	
	return 0;

     

}