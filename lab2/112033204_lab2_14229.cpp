#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *last;
    struct node *next;
}node;
node *tail=NULL,*head=NULL;
void intail(int number);
void inhead(int number);
void rmtail();
void rmhead();
void output();
void search(int number);
int main()
{
    int n,i;
    cin>>n;
    string command[n];
    int number[n];
    for(i=0;i<=n-1;i++)
    {
        cin>>command[i];
        if(command[i] == "IT")
        {
            cin>>number[i];
        }else
        if(command[i]=="IH")
        {
            cin>>number[i];
        }else
        if(command[i] == "S")
        {
            cin>>number[i];
        }
    }
    for(i=0;i<=n-1;i++)
    {
        //cin>>command;
        if(command[i] == "IT")
        {
            //cin>>number;
            intail(number[i]);
        }else
        if(command[i] == "IH")
        {
            //cin>>number;
            inhead(number[i]);
        }else
        if(command[i] == "RT")
        {
            rmtail();
        }else
        if(command[i] == "RH")
        {
            rmhead();
        }else
        if(command[i] == "O")
        {
            output();
        }else
        if(command[i] == "S")
        {
            search(number[i]);
        }
    }
    return 0;
}
void intail(int number)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = number;
    newnode->last = NULL;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    {
        tail->next = newnode;
        newnode->last = tail;
        tail = tail->next;
    }
}
void inhead(int number)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = number;
    newnode->last = NULL;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    {
        newnode->next=head;
        head->last =newnode;
        head = newnode;
    }
}
void rmtail()
{
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
        return;
    }
    if(head!=NULL && tail !=NULL)  //list is empty
    {
        tail = tail->last;
        tail->next = NULL;
    }
}
void rmhead()
{
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
        return;
    }
    if(head!=NULL && tail !=NULL)  //list is empty
    {
        head = head->next;
        head->last=NULL;
    }
}
void output()
{
    if(head == NULL)
    {
        cout<<"E"<<endl;
        return;
    }
    node *t;
    t = head;
    while(t->next!= NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    if(t!=NULL)cout<<t->data;
    cout<<endl;
}
void search(int number)
{
    int found = 0;
    node *t;
    t = head;
    if(head==NULL || tail == NULL)  //list is empty
    {
        cout<<"E"<<endl;
        return ;
    }
    while(t!= NULL)
    {
        if(number==t->data)
        {
            found=1;
            break;
        }
        t = t->next;
    }
    if(found==1){
        cout<<"Y"<<endl;
    }else{
        cout<<"N"<<endl;
    }
}
