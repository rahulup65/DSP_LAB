#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{

char data;
struct node *next;


}*top=NULL,*start=NULL;

void insert(char ch)
{
struct node *t,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=ch;
    t=start;

    if(start==NULL)
    {
     start=temp;
    }
    else
    {
    while(t->next!=NULL)
    t=t->next;
    t->next=temp;

    }


}





void push (char symbol)
{

    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=symbol;
    if(top==NULL)
    {
     top=p;
     p->next=NULL;

    }
    else
    {

    p->next=top;
    top=p;

    }
}

char  pop()
{
struct node *x,*y;
char k;
if(top==NULL)
{
    printf("stack underflow\n");
    return 0;

}
else
{
x=top;
top=top->next;
k=x->data;
free(x);
x=NULL;
return k;


}



}


void display()
{
    struct node *to;
    if(start==NULL);
    to=start;
    while(to!=NULL)
    {
        printf("%c",to->data);
        to=to->next;

    }

    }

int pre(char ch)
{

if(ch=='^')
return (5);
else if(ch=='*' || ch== '/')
return (4);
else if (ch== '+' || ch== '-')
return (3);
else
return (2);
}

void intopost(char infix[])
{

    int len;
    int index=0;
    char symbol,temp;
    len= strlen(infix);
    while(len>index)
    {
        symbol=infix[index];

        switch(symbol)
        {

        case '(':
        push(symbol);
        break;

        case ')':
        temp=pop();
        while(temp!='(')
        {
        insert(temp);
        temp=pop();
        }
        break;

        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
        if(top==NULL)
        {
            push(symbol);
    

        }
        else
        {
        while(top!=NULL && (pre(top->data)>=pre(symbol)))
        {
            temp=pop();
            insert(temp);

        }
        push(symbol);

        }   
        break;
        default:
        insert(symbol);

         }
         index=index+1;


    }
    while(top!=NULL)
    {
    temp=pop();
    insert(temp);

    }
    display();
    return;
}

int main()
{
char infix[50];
scanf("%[^\n]%*c",infix); 
intopost(infix);
getchar();
return 0;
}
