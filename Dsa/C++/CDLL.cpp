#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
class CDL_L{
    node* start;
    public:
    CDL_L();
    ~CDL_L();
    void insert_Begin(int);
    void insert_End(int);
    void insert(int,int);
    node* search(int);
    void print();
    void del_begin();
    void del_end();
    void del(int);
};
CDL_L::~CDL_L(){
node* ptr=start;
node* d_node;
while(ptr!=start->prev)
{
d_node=ptr;
ptr=ptr->next;
delete d_node;
}
delete ptr;
delete start;
}
void CDL_L::del(int value)
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
        else if(ptr==start->prev)
        {
            del_end();
            return;
        }
        else{
           node *next_node=ptr->next;
           node *prev_node=ptr->prev;
           prev_node->next=next_node;
           next_node->prev=prev_node;
           delete ptr;
           return;
        }
        
    }
}
void CDL_L::del_end()
{
if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return ;
}
        node *ptr;
        ptr=start;
        while(ptr!=start->prev)
           {ptr=ptr->next;}
        start->prev=ptr->prev;
        (ptr->prev)->next=start;
        delete ptr;
}
void CDL_L::del_begin()
{
    
    if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return;
}
    node *ptr;
    ptr =start;
    (start->next)->prev=start->prev;
    start->prev->next=start->next;
    start=start->next;
    delete ptr;
}
//void CDL_L::set_ln(node *t){
    //start->prev=t;}
node* CDL_L::search(int value)
{
node *ptr;
ptr=start;
while(ptr!=start->prev)
{
if(ptr->data==value)
{
    return ptr;
}
ptr=ptr->next;
}
if(ptr->data==value){
    return ptr;
}
else{
return NULL;}
}
void CDL_L::print()
{node* ptr;
ptr=start;
if(start==NULL)
{
    cout<<"List Is Empty"<<endl;
    return;
}
while(ptr!=start->prev)
{
cout<<ptr->data<<" ";
ptr=ptr->next;
}if(ptr==start->prev)
{cout<<ptr->data<<" ";}
cout<<endl;}
void CDL_L::insert(int Value,int Data)
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
(ptr->next)->prev=new_node;
ptr->next = new_node;
return;
}

}
void CDL_L::insert_End(int value)
{
     if(start==NULL)
    {
        insert_Begin(value);
    }
    else{
         node *ptr;
         node *new_node= new node; 
         new_node->data = value;
         new_node->next = start;
         ptr =start;
         while(ptr!=start->prev)
         {
            ptr = ptr->next;
         }
         new_node->prev=ptr;
         ptr->next=new_node;
         start->prev=new_node;
    }
}
void CDL_L::insert_Begin(int value)
{
    node *new_node=new node;
    new_node->data=value;
    new_node->next=start;
    new_node->prev=NULL;
    if(start)
     {  new_node->prev=start->prev;
         (start->prev)->next=new_node;
        start->prev=new_node;
        }
    else
      { new_node->prev=new_node;
        new_node->next=new_node;}
    start=new_node;
}
CDL_L::CDL_L()
{
    start=NULL;
}
