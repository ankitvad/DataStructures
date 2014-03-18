//Queues using Linked list.FIFO
#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE
{
	int data;
	NODE*next;

};

class queue
{
private:
	NODE*front;
	NODE*rear;
public:
	queue()
	{
		front=rear=NULL;
	};
	void push();
	void pop();
	void display();
	~queue();
};

void queue::push()
{
	NODE*temp;
	temp=new NODE;
	cout<<"\n Please enter the element: ";
		cin>>temp->data;
		temp->next=NULL;
	if(rear==NULL)
			
		{front=rear=temp;}
	else
	rear->next=temp;
	rear=temp;		
}
void queue::pop()
{
	if(rear==NULL)
		cout<<"\n Empty queue.";
	else
	{
		NODE*temp=front;
		cout<<"\nDeleted"<<front->data;
	front=front->next;
	delete temp;
    if(front==NULL)
    	{rear=NULL;}
    }

}
void queue::display()
{
	NODE*temp=front;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}
queue::~queue()
{
	NODE*temp=front;
	while(front!=NULL)
		front=front->next;
	delete temp;

}

int main()
{
	queue q1;
	int num;
	char choice;
	do
	{
			cout<<"\nPlease enter the number based on your choice.\n1.Push an element in the queue.\t2.Pop an element from the queue.\n3.View queue.\t4.Exit";
            cin>>num;
            switch(num)
            {
            	case 1: q1.push();break;
            	case 2: q1.pop();break;
            	case 3: q1.display();break;
            	case 4: exit(0);break;
            	default: cout<<"\n Please enter the collect number from 1-4";

            }  
            cout<<"\nDo you wish to continue ? (y/n)";
            cin>>choice;
            

	}while(choice=='y'||choice=='Y');
	
	return 0;

     

}