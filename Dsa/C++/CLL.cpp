#include <iostream>
using namespace std;
struct node{
     public:
     int data;
     node *next;
};
class CLL{
 node *start;
 node *last;
 public:
 CLL();
 ~CLL();
 void In_Beginnings(int);
 void In_Ends(int);
 node *Search(int);
 void In_Specific(int,int);
 void del_Beginnings();
 void del_Ends();
 void del_Specific(int);
 void Print();
 void end_of();
};
void CLL::end_of()
{
    cout<<"this->"<<last->data;
    cout<<endl;
}
CLL::~CLL()
{
node *ptr;
node *temp;
ptr=start;
while (ptr !=last)
{
temp=ptr;
ptr=ptr->next;
delete temp;
}
delete start;
delete ptr;
delete last;
//cout<<"Deletion Complete!"<<endl;
}
void CLL::del_Specific(int Value)
{
    node *ptr=start;
    node *temp;
temp=Search(Value);
if(start==NULL)
{
    cout<<"List Is Empty!"<<endl;
    return;
}
if(temp==start)
{
    del_Beginnings();
    return;
}
else if(temp==last)
{
    del_Ends();
    return;
}
else{
while(ptr->next==temp)
{
    ptr=ptr->next;
}
ptr->next=temp->next;
temp->next=NULL;
delete temp;
return;
}
cout<<"Invalid Specifications"<<endl;
}
void CLL::Print()
{
if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return;
}
node *ptr;
ptr=start;
while(ptr!=last)
{
cout<<ptr->data<<" ";
   ptr=ptr->next;
}
cout<<last->data;
cout<<endl;
}
void CLL::del_Ends()
{

if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return;
}
node *ptr;
ptr=start;
while((ptr->next)!=last)
{
    ptr=ptr->next;
}
ptr->next=last->next;
delete last;
last=ptr;
}
void CLL::del_Beginnings() {
    node *ptr;
    ptr =start;
    if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return ;
}
    else if(start->next!=last)
    {
        start=start->next;
        delete ptr;
        return;
    }
    else
    {
        start=NULL;
        last=NULL;
        delete ptr;
        return;
    }
}
void CLL::In_Specific(int Value,int Data)
{
node *ptr;
ptr=Search(Value);
if(ptr!=NULL)
{
node *new_node;
new_node = new node;
new_node->data = Data;
new_node->next = ptr->next;
if(ptr==last)
{
    last=new_node;
}
ptr->next = new_node;
return;
}
}
node * CLL::Search(int Value)
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
void CLL::In_Ends(int Value){
    if(start==NULL)
    {
        In_Beginnings(Value);
    }
    else{ 
         node *new_node= new node; 
         new_node->data = Value;
         new_node->next = start;
         last->next =new_node;
         last=new_node;
    }
}
void CLL::In_Beginnings(int Value)
{
node *new_node=new node;
new_node->data = Value;
new_node->next = start;
if(last==NULL)
{
    last=new_node;
} 
start = new_node;
}
CLL::CLL(){
start=NULL;
last=NULL;
 }