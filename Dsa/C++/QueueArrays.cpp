#include<iostream>
using namespace std;
class Queue{
private:
int front,rear,capacity;
int *ptr;
public:
Queue(int);
void enqueue(int);
void dequeue();
int get_front();
int get_rear();
~Queue();
bool overflow();
bool underflow();
int count();
void show();
};
bool Queue::underflow()
{
    if((front>capacity&&rear>capacity)||(front==-1&&rear==-1))
    {
return true;    }
else
{
    return false;
}
}
bool Queue::overflow(){
    if(rear==capacity||rear==front-1)
{return true;}
else{
    return false;
}
}
int Queue::count()
{
    if(front<rear)
    {
        return rear-front+1;
    }
    else if (!rear&&!front){
return 1;
    }
    else if(front==rear)
    {
        return 0;
    }
    else{
        return capacity-front+rear;
    }
}
Queue::~Queue()
{
    delete ptr;
}
int Queue::get_front()
{
    return ptr[front];
}
int Queue::get_rear()
{
    return ptr[rear];
}
void Queue::show()
{
    if(rear!=-1&&front!=-1)
    {
if(rear>=front)
{
    for(int i=front; i<=rear; i++)
    {
        cout<<ptr[i]<<" ";
    }
}
else{
    for(int i=0; i<=rear; i++)
    {
        cout<<ptr[i]<<" ";
    }
    for(int i=front;i<capacity;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
    }
else{
    cout<<"Queue is Empty!";
}
cout<<endl;
}
void Queue::dequeue(){
    if((front==-1&&rear==-1))
    {
        cout<<"Queue is Empty!"<<endl;
    }
    else if(front==rear)
    {
 front=-1;
 rear=-1;
    }
    else{
        if(front==capacity&&rear!=capacity)
        {
            front=0;
        }
        else{
            front++;
        }
    }
}
void Queue::enqueue(int data)
{
if(rear==capacity||rear==front-1)
{cout<<"Queue is full!"<<endl;}
else{
if(front==-1 && rear==-1)
{front=0;}
else if(front!=0&&rear==capacity)
{rear=-1;}
ptr[++rear]=data;
}
}
Queue::Queue(int size){
    front=-1;
    rear=-1;
    capacity=size-1;
    ptr=new int[capacity];
}