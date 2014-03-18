//C++ iplementation.
# include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct employee
	{
	int data;
	};
void read(employee &s)
	{
	cout<<"\n Enter date:";
	cin>>s.data;
	}
void disp(employee &s)
	{
	 cout<<"\nData is:"<<s.data<<"\t";
	}
 class queue
       {
        employee a[20];
	  int front, rear, max;
        public:
		queue()
			{
			front=rear=-1;
			max=19;
			}
			void add();
			void del();
			void display();
			int isfull();
			int isempty();
		};
	int queue::isfull()
            {
             if((front==rear+1)||(front==0)&&(rear==max)))
			return 1;
		else
		return 0; 
	}
	void queue::add()
		{
		if(isfull())
		    cout<<"\n queue overflow";
            else
		     {
			employee temp;
			read(temp);
			if(isempty())
			  front=rear=0;
                   else
				if(rear==max)
                  		rear=0;
                  	else
			   		rear++;
			 
                  a[rear]=temp;
			}
		}

void queue: :del( )
{
	if(isempty())
		cout<<”\n Queue underflow! !”;
      else
		{	employee temp;
			temp=a[front];
		  cout<<”Data :”<<temp.data<<”remove from queue\n”;
			if(front==rear)
                     front=rear=-1;
			else
				if(front==max)
                     		front=0;
				else
			   		front++;
		}
	}
void  queue : :display( )
{
	if(isempty())
	    cout<<”\n Queue underflow!!”
	else
	{
	if(front<=rear)
	  {
	   for(int i=front;i<=rear;i++)
	        disp(a[i]);
	    }
	else
	    {
	    for(int i=front;i<=max;i++)
		 disp(a[i]);
          for(i=0;i<=rear;i++)
               disp(a[i]);
		}
	    }
	}


int main()
      {
       int ch;
       char c;
       queue ob;
       do
           {
            
            cout << “\n#######MENU######”;
		cout << “\n1.ADD A RECORD IN QUEUE.”;
            cout << “\n2.REMOVE A RECORD FROM QUEUE.”;
		cout << “\n3.DISPLAY THE QUEUE.”;
		cout << “\n4.QUIT.”;
		cout << “\n ENTER YOUR CHOICE : :”;
		cin >> ch;
		switch (ch)
		{	case 1	:	ob.add();
						break;
			case 2	:	ob.del();
						break;
			case 3 	:	ob.display();
						break;
			case 4	:	exit(0);break;
			default : cout << “\n\n WRONG CHOICE !!!”;
		}
		
		} while (ch!=4);
		
		return 0;
	}

