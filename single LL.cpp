#include<iostream>
#include<conio.h>

using namespace std;

class list
{ private:
	int info;
	public:
		list *next;
		void input()
		{
		cin>>info;
	}
		void output()
		{
			cout<<info;
		}
};
int main()
{   
	list *head, *temp, *last;
	char ch;
	head=NULL;
	temp=NULL;
	temp=new list;
	if(temp==NULL)
	{
		cout<<"insufficient memory space";
	}
	temp->input();
	if(head==NULL)
	{ head=last=temp;
	}
	else
	{ last->next=temp;
	last=temp;
	cout<<"continue?";
	cin>>ch;
}
while(ch=='Y' || ch=='y')
temp=head;
while(temp!=NULL)
{ temp->output();
temp=temp->next;
}
getch();
return 0;
}
