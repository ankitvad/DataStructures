// convert.h

const char SIZE=100;

class stack
{
public:
        stack();//construtor
        int isempty();
        int isfull();
        void push(char num);
        void pop(char &elm);
        void cntres();
        int topnum;
        void print();
        //void result(stack &post);
private:
        char data[SIZE];
        int top;
};

// convert.cpp
#include<iostream>
// #include"convert.h"
#include<cstddef>
#include<cstring>

using namespace std;
//calling constructor to define global value for te class.
stack::stack()
{
        top=-1;
        topnum=top;
}

int stack::isempty()
{
        return top==-1;

}

int stack::isfull()
{
        return top==SIZE-1;
}

void stack::push(char elm)
{
if(isfull())
        cout<<"Cannot Add New Item , No Free Space ."<<endl;
else
        {
                top++;
                data[top]=elm;
                topnum=top;
        }

}
void stack::pop(char &elm)
{
        if(isempty())
                cout<<"There's No Data ."<<endl;
        else
        {
                topnum=top;
                elm=data[top];
                top--;
                
        }
}


void stack::print()
{       int i;
        cout<<"PostFix Formula : ";
        for(i=0;i<=top;i++)
        cout<<data[i];
}
/*
void stack::result(stack &post)
{
        int i;
        int a,b,c;
        char oper;
        int res=0;
        int loop=strlen(post.data);
        for(i=0;i<=loop;i++)
{
        if(post.data[i]=='+'||post.data[i]=='-'||post.data[i]=='*'||post.data[i]=='/')
        {
                pop(oper);
                a=oper-48;
                pop(oper);
                b=oper-48;
                if (post.data[i]=='+')
                        c=a+b;
                else if (post.data[i]=='-')
                        c=a-b;
                else if (post.data[i]=='*')
                        c=a*b;
                else c=a/b;

                oper=c+48;
                push(oper);

        }
        push(post.data[i]);

}
pop(oper);
res=oper-48;
cout<<res<<endl;

}*/

// main
#include<iostream>
// #include"convert.h"
#include<cstring>

using namespace std;

int main()
{
        stack op;
        stack post;
        int a;
        stack res;
        char infex[SIZE];
        //cin.get to pass the value as well as the size parameter to the input function so as to take in the value.
        cout<<"Please Enter Infex Formula :";
        cin.get(infex,SIZE);
        char OpValue;
        char ch;
        int lenght;
        lenght=strlen(infex);
        for(int i=0;i<lenght;i++)
        {
                if(infex[i]=='+'||infex[i]=='-'||infex[i]=='*'||infex[i]=='/'||infex[i]=='('||infex[i]==')')
                {
                        if(infex[i]=='*'||infex[i]=='/'||infex[i]=='(')
                                op.push(infex[i]);
                        else if(infex[i]=='+'||infex[i]=='-')
                        {
                                if(op.topnum=='*'||op.topnum=='/')
                                {
                                        op.pop(ch);
                                        OpValue=ch;
                                        while(ch!='('&& !op.isempty())
                                        {
                                                post.push(ch);
                                                op.pop(ch);

                                        }
                                        op.push(infex[i]);
                                }
                                else
                                        op.push(infex[i]);
                                }
                        else if(infex[i]==')')
                        {
                                op.pop(ch);
                                OpValue=ch;
                                while(OpValue!='(')
                                {
                                        post.push(OpValue);
                                        op.pop(ch);
                                        OpValue=ch;
                                }

                        }


                        }
                else
                        post.push(infex[i]);

                }
        while(!op.isempty())
        {
                op.pop(ch);
                OpValue=ch;
                post.push(OpValue);     
        }

        post.print();
        cout<<endl;

        cout<<"RESULT OF INFIX : ";
        //res.result(post);

cin>>a;
return 0;
}