#include <iostream>
#include <stdio.h>
using namespace std;

class stack 
{
	
	int arr[20];
	int top,max;
	
	public:
	stack()
	{
		top=-1;
		max=19;
	}
	void push();
	void pop();
	void display();
};

void stack::push()
{
	if (top==max)
	{
		cout<<"\nOverflow";
	}
	else
	{
		int d;
		cout<<"Enter the element to pushed in";
		cin>>d;
		top++;
		arr[top]=d;
		cout<<d<" Pushed into stack";
	}
}
void stack::pop()
{
	if (top==-1)
	{
		cout<<"\n Underfow";
	}
	else
	{
		cout<<arr[top]<"POPPED FROM STACK";
		top--;
	}
}
void stack::display()
{
	int i;
	for (i=top;i>=0;i--)
	cout<<"\n"<<arr[i];
}

int main()
{
	int ch,n,f;
	char c;
	stack ob;
	do
	{
		
		cout<<"\n\t\tMENU";
		cout<<"\n1. PUSH INTO STACK";
		cout<<"\n2. POP FROM STACK";
		cout<<"\n3. DISPLAY THE STACK";
		cout<<"\n4. EXIT";
		cout<<"\n ENTER YOUR CHOICE";
		cin>>ch;

		switch(ch)
		{
			case 1:
			ob.push();
			break;
		    case 2:
			ob.pop();
			break;
		    case 3:
			ob.display();
		    break;
		    case 4:
			cout<<"\n exiting";
			break;
			default: cout<<"\n Please enter a valid number ";		
		}    
		    
		    cout<<"\nDo you want to continue";
	 	    cin>>c;			
	    
    }while((c=='y')||(c=='Y'));
	
	cin>>f;
return 0;
}
