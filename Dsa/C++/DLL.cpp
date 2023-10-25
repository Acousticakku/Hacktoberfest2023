#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
class DLL{
node *start;
public:
DLL();
~DLL();
void insert_Begin(int);
void insert_End(int);
node *search(int);
void insert(int,int);
void del_begin();
void del_end();
void del(int);
void print();
};
DLL::~DLL(){
node *ptr=start;
node *temp;
while(ptr!=NULL)
{
    temp=ptr;
    ptr=ptr->next;
    delete temp;
}
delete start;
}
void DLL::print()
{node* ptr;
ptr=start;
if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return;
}
while(ptr!=NULL)
{
cout<<ptr->data<<" ";
ptr=ptr->next;
}
cout<<endl;}
void DLL::del(int value)
{
    if(start==NULL)
    {
        cout<<"List->Empty"<<endl;
        return;
    }
    else{
        node *ptr;
        ptr=search(value);
        if(ptr==start)
        {
            del_begin();
            return ;
        }
        else if(ptr->next==NULL)
        {
            del_end();
            return;
        }
        else{
           ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           ptr->next=NULL;
           ptr->prev=NULL;
           delete ptr;
           return;
        }
        
    }
}
void DLL::del_end()
{
if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return ;
}
        node *ptr;
        ptr=start;
        while(ptr->next!=NULL)
           {ptr=ptr->next;}
        if(ptr->prev)
          {  ptr->prev->next=NULL;}
        else
            {start=NULL;}
        delete ptr;
}
void DLL::del_begin()
{
    
    if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return;
}
    node *ptr;
    ptr =start;
    start = start->next;
    if(ptr->next)
    {start->next->prev=NULL;}
    delete ptr;
}
void DLL::insert(int Value,int Data)
{
node *ptr;
ptr=search(Value);
if(ptr)
{
node *new_node;
new_node = new node;
new_node->data = Data;
new_node->next = ptr->next;
new_node->prev=ptr;
ptr->next = new_node;
new_node->next->prev=new_node;
return;
}

}
node *DLL::search(int value)
{
node *ptr;
ptr=start;
while(ptr!=NULL)
{
if(ptr->data==value)
{
    return ptr;
}
ptr=ptr->next;
}
return NULL;
}
void DLL::insert_End(int value)
{
     if(start==NULL)
    {
        insert_Begin(value);
    }
    else{
         node *ptr;
         node *new_node= new node; 
         new_node->data = value;
         new_node->next = NULL;
         ptr =start;
         while(ptr->next !=NULL)
         {
            ptr = ptr->next;
         }
         new_node->prev=ptr;
         ptr->next=new_node;
    }
}
void DLL::insert_Begin(int value)
{
    node *new_node=new node;
    new_node->data=value;
    new_node->next=start;
    new_node->prev=NULL;
    if(start)
        start->prev=new_node;
    start=new_node;
}
DLL::DLL()
{
    start = NULL; 
}