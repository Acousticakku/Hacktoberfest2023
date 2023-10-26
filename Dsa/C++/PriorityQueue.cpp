#include <iostream>
using namespace std;
struct node{
    int pno;
    int data;
    node *next;
};
class PriorityQueue{
private:
node *start;
public:
PriorityQueue();
void enqueue(int,int);
void dequeue();
void print();
int get_p_element();
int get_p();
~PriorityQueue();
bool empty();
}; 
bool PriorityQueue::empty()
{
    if(start)
    {return false;}
    else{
        return true;
    }
}
PriorityQueue::~PriorityQueue()
{
    while(!empty())
    {
        dequeue();
    }
}
int PriorityQueue::get_p()
{   if(start)
       {return start->pno;}
    else 
       {return -100001;}
}
int PriorityQueue::get_p_element()
{
    if(start)
       {return start->data;}
    else 
       {return -100001;}
}
void PriorityQueue::dequeue(){
    node *ptr=start;
    start=start->next;
    delete ptr;
}
PriorityQueue::PriorityQueue(){
start=NULL;
}
void PriorityQueue::enqueue(int p,int value)
{
    node *new_node=new node;
    new_node->data=value;
    new_node->pno=p;
    new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;
    }
    else{
        node *ptr=start;
        node *prev=start;
        while(ptr!=NULL&&ptr->pno<=p)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr==start)
        {
        new_node->next=start;
        start=new_node;
        }
        else if(ptr==NULL)
        {
            prev->next=new_node;
        }
        else
       {new_node->next=ptr;
        prev->next=new_node;}
    }

}
void PriorityQueue::print(){
    node *ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}