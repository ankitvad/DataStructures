//to reverse  a linked list
#include <iostream>
#include <conio.h>
using namespace std;
struct  node
{
	int info;
	node * next;
} *head = NULL, *temp, *temp2, *newptr;

int main()
{
	int count = 0;          // count stores the no of elements in the linked list
	//accept the linked list
	cout<<"\nEnter elements of linked list: (-9999 to terminate)\n";
	do
	{
		newptr = new node;
		cin>>newptr -> info;

		if(newptr -> info == -9999)
		{
			delete newptr;
			break;
		}
		newptr -> next = head;
		head = newptr;
		count++;= 
	}while(1);

	temp = head;
	while(temp -> next -> next != NULL)
		temp = temp -> next;
	
	temp -> next -> next = head;
	head = temp -> next;
	temp -> next = NULL;

	for(int i=0; i<count -2 ; i++)
	{
		temp = head;
		while(temp -> next -> next != NULL)
			temp = temp -> next;

		temp2 = head;
		for(int j=0; j< i; j++)
			temp2 = temp2 -> next;

		temp -> next -> next = temp2 -> next;
		temp2 -> next = temp -> next;
		temp -> next = NULL;
		

	}

	cout<<"\nInverted list is";
	temp = head;
	while(temp != NULL)
	{
		cout<<temp -> info<<" ->  ";
		temp = temp -> next;
	}
	getch();
	return 0;
}
