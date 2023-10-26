#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class Queue{
private:
node *rear,*front;
public:
Queue();
void enqueue(int);
void Print(); 
void dequeue();
int get_front();
int get_rear();
~Queue();
int count();
void sort();
};
void sort(){
    
}
int Queue::count(){
node *ptr=front;
int ctr=0;
while(ptr)
{
ptr = ptr->next;
ctr++;
}
return ctr;
}
Queue::~Queue()
{
    node *ptr=front;
    while(ptr)
    {
        node *prev=ptr;
        ptr=ptr->next;
        delete prev;
    }
    delete ptr;
}
int Queue::get_front()
{
    if(front)
    {return front->data;}
    else{return -1;}
}
int Queue::get_rear()
{
    if(rear)
    {return rear->data;}
    else{return -1;}
}
void Queue::dequeue() {
    if(rear==NULL)
    {
        cout<<"Queue is empty!"<<endl;
    }
    else if(front==rear)
    {
       node* ptr=front;
        front=NULL;
        rear=NULL;
        delete ptr;
    }
    else{
        node *ptr=front;
        front=front->next;
        delete ptr;
    }
}
void Queue::Print()
{node* ptr;
ptr=front;
if(front==NULL)
{
    cout<<"Queue Is Empty"<<endl;
    return;
}
while(ptr!=NULL)
{
cout<<ptr->data<<" ";
   ptr=ptr->next;
}
cout<<endl;
}
void Queue::enqueue(int value)
{
    node *new_node=new node;
    new_node->data=value;
    new_node->next=NULL;
    if(rear==NULL&&front==NULL)
    {front=new_node;}
    else{
    rear->next=new_node;}
    rear=new_node;
}
Queue::Queue()
{
    rear=NULL;
    front=NULL;
}