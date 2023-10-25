#include<iostream>
using namespace std;
class BasicArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        BasicArray(int);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get(int);
        int count();
        int find(int);
        ~BasicArray();
        void print();
};
int BasicArray::find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
BasicArray::~BasicArray()
{
    delete[]ptr;
}
int BasicArray::count()
{
    return lastIndex+1;
}
int BasicArray::get(int index)
{
    if(index>=0 && index<=lastIndex)
        return ptr[index];
}
bool BasicArray::isFull()
{
    return lastIndex==capacity-1;
}
void BasicArray::del(int index)
{
    int i;
    if(isEmpty())
        cout<<endl<<"BasicArray is empty"<<endl;
    else if(index<0 || index>lastIndex)
        cout<<endl<<"Invalid Index"<<endl;
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    
}
void BasicArray::edit(int index,int data)
{
    if(index>=0&&index<=lastIndex)
        ptr[index]=data;
}
void BasicArray::insert(int index,int data)
{
    int i;
    if(lastIndex==capacity-1)
        cout<<endl<<"BasicArray is already full"<<endl;
    else if(index<0 || index>lastIndex+1)
    {
        cout<<"Invalid Index"<<endl;
    }
    else
    {
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
void BasicArray::append(int data)
{
    if(lastIndex==capacity-1)
        cout<<endl<<"BasicArray is already full"<<endl;
    else
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
bool BasicArray::isEmpty()
{
    return lastIndex==-1;
}
BasicArray::BasicArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];

}
void BasicArray::print()
{
    for(int i=0;i<=lastIndex;i++)
    {
        cout<<get(i)<<" ";
    }
    cout<<endl;
}