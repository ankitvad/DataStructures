//Stacks-LiFo(linked list imlementation)
#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE
{
	int data;
	NODE*next;
};

class stack
{
private:
	NODE*top;
public:
	stack()
	{
		top=NULL;
	};
    void push();
    void pop();
    void display();
//Destructor to delete stuff and free up memory.
    ~stack();

};

void stack::push()
{
	NODE*temp;
	temp=new NODE;
	if(!temp)
		cout<<"\noverflow Condition.";
	else
 {
	cout<<"\nPlease insert the data : ";
	cin>>temp->data;
	//temp's next is pointing to top, so that the LIFO poping is possible.
	temp->next=top;
	top=temp;
 }
}
void stack::pop()
{
    NODE*temp=top;
	if(top!=NULL)
	{
	cout<<temp->data<<"\tDeleted.";
	top=top->next;
	delete temp;
    }
    else
    cout<<"\n Underflow condition.";
}
void stack::display()
{
	if(top==NULL)
		cout<<"\n stack is empty";
	else
	{
	NODE*temp=top;
	while(temp!=NULL)
	{
	  cout<<temp->data<<"\t";
	  temp=temp->next;
	}
     }

}
stack::~stack()
{
	while(top!=NULL)
	{
	NODE*temp=top;
	top=top->next;
	delete temp;
    }
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