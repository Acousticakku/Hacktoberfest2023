#include<iostream>
using namespace std;
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        DynArray(int);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get(int);
        int count();
        int find(int);
        void doubleArray();
        void halfArray();
        int size();
        ~DynArray();
        void print();
};
void DynArray::print()
{
    for(int i=0;i<=lastIndex;i++)
    {
        cout<<get(i)<<" ";
    }
    cout<<endl;
}
void DynArray::del(int index)
{
    int i;
    if(isEmpty())
        cout<<endl<<"Array is empty";
    else if(index<0 || index>lastIndex)
        cout<<endl<<"Invalid Index";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
        if(capacity/2>=lastIndex+1 && capacity>1)
            halfArray();
    }
    
}
void DynArray::insert(int index,int data)
{
    int i;
    if(index<0 || index>lastIndex+1)
        cout<<endl<<"Invalid Index";
    else
    {
        if(isFull())
            doubleArray();
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
void DynArray::append(int data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}
int DynArray::size()
{
    return capacity;
}
void DynArray::halfArray()
{
    int *temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
void DynArray::doubleArray()
{
    int *temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
DynArray::DynArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];

}
bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
void DynArray::edit(int index,int data)
{
    if(index>=0&&index<=lastIndex)
        ptr[index]=data;
}
bool DynArray::isFull()
{
    return lastIndex==capacity-1;
}
int DynArray::get(int index)
{
    if(index>=0 && index<=lastIndex)
        return ptr[index];
    cout<<endl<<"Invalid index or empty array";
    return -1;
}
int DynArray::count()
{
    return lastIndex+1;
}
DynArray::~DynArray()
{
    delete[]ptr;
}
int DynArray::find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}