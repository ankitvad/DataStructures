#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NULL 0
struct info
{
 int data;
 struct info *next;
};
struct info *head,*temp,*disp;
void additem();
void delitem();
void display();
int size();
void search();
void main()
{
int choice;

while(1)
{
printf("\n1.Add records");
printf("\n2.Delete records");
printf("\n3.Display records");
printf("\n4.Count no. of items in the list");
printf("\n5.Searching an item in the list");
printf("\n6.Exit");
printf("\nEnter your choice:");
scanf("%d",&choice);
fflush(stdin);
switch(choice)
{
case 1:
   additem();
   break;
case 2:
   delitem();
   break;
case 3:
   display();
   break;
case 4:
   printf("\nThe size of the list is %d",size());
   break;
case 5:
   search();
   break;
case 6:
   exit(0);
}
}
}
void additem()
{
struct info *add;
char proceed='y';
while(toupper(proceed)=='Y')
{
add=(struct info*)malloc(sizeof(struct info));
printf("Enter data:");
scanf("%d",&add->data);
fflush(stdin);
if(head==NULL)
{
head=add;
add->next=NULL;
temp=add;
}
else
{
temp->next=add;
add->next=NULL;
temp=add;
}
printf("\nWant to proceed y/n");
proceed=getchar();
fflush(stdin);
}
}
void delitem()
{
struct info *curr,*prev;
int tdata;
if(head==NULL)
{
printf("\nNo records to delete");
return;
}
printf("\nEnter the data to delete");
scanf("%d",&tdata);
fflush(stdin);
prev=curr=head;
while((curr!=NULL)&&(curr->data!=tdata))
{
prev=curr;
curr=curr->next;
}
if(curr==NULL)
{
printf("\nData not found");
return;
}
if(curr==head)
       head=head->next;
else
{
/*for inbetween element deletion*/
prev->next=curr->next;
/*for the last element deletion*/
if(curr->next==NULL)
       temp=prev;
}
free(curr);
}
void display()
{
if(head==NULL)
{
printf("\nNo data to display");
return;
}
for(disp=head;disp!=NULL;disp=disp->next)
{
printf("Data->%d",disp->data);
}
}
int size()
{
int count=0;
if(head==NULL)
      return count;
for(disp=head;disp!=NULL;disp=disp->next)
      count++;
return count;
}
void search()
{
int titem,found=0;
if(head==NULL)
{
printf("\nNo data in the list");
return;
}
printf("\nEnter the no. to search:");
scanf("%d",&titem);
for(disp=head;disp!=NULL&&found==0;disp=disp->next)
{
if(disp->data==titem)
    found=1;
}
if(found==0)
       printf("\nSearch no. is not present in the list");
else
       printf("\nSearch no. is present in the list");
return;
}
