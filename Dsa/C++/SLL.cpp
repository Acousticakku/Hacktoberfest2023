//Singly Linked List
#include<iostream>
#include<stdio.h>
using namespace std;
struct node{ 
    public:
     int data;
     node *next;
};
class SLL{
 node *start;
 public:
 SLL();
 ~SLL();
 void set_start(node*);
 node* get_start();
 void In_Beginnings(int);
 void In_Ends(int);
 node *Search(int);
 void In_Specific(int,int);
 void del_Beginnings();
 void del_Ends();
 void del_Specific(int);
 void Print();
 void operator=(SLL&);
};
void SLL::operator=(SLL &s1)
{
node* ptr2=s1.get_start();
while(ptr2!=NULL)
{
    In_Ends(ptr2->data);
    ptr2=ptr2->next;
}
}
void SLL::set_start(node* t)
{
start=t;
}
node* SLL::get_start() { return start; }
SLL::~SLL()
{
node *ptr;
node *temp;
ptr=start;
while (ptr !=NULL)
{
temp=ptr;
ptr=ptr->next;
delete temp;
}
delete ptr;
//cout<<"Deletion Complete!"<<endl;
}
void SLL::del_Specific(int Value)
{
    node *ptr;
    node *temp;
ptr=start;
if(start==NULL)
{
    cout<<"List Is Empty!"<<endl;
    return;
}
if(start->data==Value)
{
    del_Beginnings();
    return;
}
while(ptr!=NULL)
{
    if(ptr->data==Value)
    {
temp->next=ptr->next;
delete ptr;
return;
    }
temp=ptr;
ptr=ptr->next;
}
cout<<"Invalid Specifications"<<endl;
}
void SLL::Print()
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
cout<<endl;
}
void SLL::del_Ends() 
{
    node *ptr;
    ptr =start;
if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
}
    while((ptr->next)->next!=NULL)
    {ptr =ptr->next;}
    delete (ptr->next);
    ptr->next=NULL;
}
void SLL::del_Beginnings() {
    node *ptr;
    ptr =start;
    if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
}
    start = start->next;
    delete ptr;
}
void SLL::In_Specific(int Value,int Data)
{
node *ptr;
ptr=Search(Value);

if(ptr!=NULL)
{
node *new_node;
new_node = new node;
new_node->data = Data;
new_node->next = ptr->next;
ptr->next = new_node;
return;
}
return;

}
node * SLL::Search(int Value)
{
node *ptr;
ptr=start;
while(ptr!=NULL)
{
if(ptr->data==Value)
{
    return ptr;
}
ptr=ptr->next;
}
return NULL;
}
void SLL::In_Ends(int Value){
    if(start==NULL)
    {
        In_Beginnings(Value);
    }
    else{
         node *ptr;
         node *new_node= new node; 
         new_node->data = Value;
         new_node->next = NULL;
         ptr =start;
         while(ptr->next !=NULL)
         {
            ptr = ptr->next;
         }
         
         ptr->next=new_node;
    }
}
void SLL::In_Beginnings(int Value)
{
node *new_node=new node;
new_node->data = Value;
new_node->next = start;
start = new_node;
}
SLL::SLL(){
start=NULL;
 }