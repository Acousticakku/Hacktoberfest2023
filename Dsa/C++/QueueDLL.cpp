#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
class Deque{
    private:
    node *front;
    node *rear;
    public:
    Deque();
    void in_front(int);
    void in_rear(int);
    void print();
    void del_front();
    void del_rear();
    auto get_front(); 
    auto get_rear();
    ~Deque();
    bool Empty();
};
bool Deque::Empty()
{
    if(front==NULL)
    {
        return true;
    }
    return false;
}
Deque::~Deque(){
    while(!Empty())
    {
        del_front();
    }
}
auto Deque::get_front() { if(!Empty()){return front->data;}
else{cout<<"Queue is empty!"<<endl;
return NULL;}}
auto Deque::get_rear() { if(!Empty()){return rear->data;}
else{cout<<"Queue is empty!"<<endl;
return NULL;} }
void Deque::del_rear() {
    if(rear==front)
    {
        front=NULL;
        rear=NULL;
        return;
    }
    node *ptr=rear;
    (rear->prev)->next=NULL;
    rear=rear->prev;
    delete ptr;
}
void Deque::del_front() {
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
        return;
    }
    node *ptr=front;
    (front->next)->prev=NULL;
    front=front->next;
    delete ptr;
}
void Deque::in_rear(int value)
{   node *new_node=new node;
    new_node->data=value;
    new_node->prev=rear;
    new_node->next=NULL;
    if(rear==NULL&&front==NULL)
    {
        rear=new_node;
        front=new_node;
    }
    else{
    rear->next=new_node;
    rear=new_node;
    }
}
void Deque::print()
{
    if(front==NULL)
    {
        cout<<"Queue is empty!"<<endl;
        return;
    }
    node *ptr=rear;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr= ptr->prev;
    }
    cout<<endl;
}
void Deque::in_front(int value)
{
    node *new_node=new node;
    new_node->data=value;
    new_node->prev=NULL;
    new_node->next=front;
    if(rear==NULL&&front==NULL)
    {
        rear=new_node;
        front=new_node;
    }
else{
    front->prev=new_node;
    front=new_node;
}
}
Deque::Deque(){
    front=rear=NULL;
}