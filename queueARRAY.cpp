//queue-FIFO
const int MAX=20;
#include <iostream>
#include <stdlib.h>
using namespace std;

class queue 
{
private:
	int array[MAX];
	int front;
	int rear;
public:
	queue()
	{
		front=-1;
		rear=-1;
	}
	void push();
	void pop();
	void display();
};

void queue::push()
{
	if(rear==MAX)
		cout<<"\n Overflow condition achieved";
	
	else if(rear==-1&&front==-1)
		{
			rear++;
		    front++;
            cout<<"\n Please enter the element:";
		    cin>>array[front];
		}
	
		else if(rear!=-1)
		{
			rear++;
		    cout<<"\n Please enter the element :";
		    cin>>array[rear];
        }
		
		
}
void queue::pop()
{
	if(front==-1)
		cout<<"\n underflow condition acheived.";
	else if(front==0&&rear==0)
	{
		front--;
	    rear--;
	    cout<<"\n Element popped from queue.";
    }
    else
    {
	 front++;
     cout<<"\n Element popped from the queue.";
    }

}
void queue::display()
{
	int i;
    cout<<"\n The element of the queue is: \n";
	for(i=front;i<=rear;i++)
		cout<<array[i]<<"\t";
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