#include <iostream>
using namespace std;
int max(int a, int b)
{
    if(a>b)
    {return a;}
    else{
        return b;
    }
}
class Heap{
private:
        int capacity;
        int lastIndex;
        int *ptr;
void edit(int,int);
void doubleArray();
void halfArray();
int count();
int find(int);
void del(int);
void append(int);
bool isFull();
public:
Heap(int);
Heap(Heap&);
void insert(int);
void show_heap();
bool isEmpty();
int Max();
void remove();
void operator=(Heap &);
void print();
int get(int);
~Heap();
};
bool Heap::isFull()
{
    return lastIndex==capacity-1;
}
Heap::~Heap()
{
    delete[]ptr;
}
void Heap::append(int data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}
void Heap::del(int index)
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
int Heap::find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
int Heap::count()
{
    return lastIndex+1;
}
void Heap::edit(int index,int data)
{
    if(index>=0&&index<=lastIndex)
        ptr[index]=data;
}
int Heap::get(int index)
{
    if(index>=0 && index<=lastIndex)
        {return ptr[index];}
    cout<<endl<<"Invalid index or empty array("<<index<<")";
    return -1;
}
void Heap::print()
{
    for(int i=0;i<=lastIndex;i++)
    {
        cout<<get(i)<<" ";
    }
    cout<<endl;
}
void Heap::operator=(Heap &h)
{
    int l=lastIndex/2;
    lastIndex=0;
    if(-1+h.count()>lastIndex)
    {
        doubleArray();
    }
    else if(-1+h.count()<=l){halfArray();}
    while(lastIndex+1<h.count())
    {
        edit(++lastIndex,h.get(lastIndex));
    }
}
Heap::Heap(Heap& h)
{
    int i=0;
    while(i+1<h.count())
    {
        append(h.get(i));
        i++;
    }
}
void Heap::remove()
{
    int Max_index;
    int N=0;
    int i=-1+count();
    edit(0,get(i));
    del(i);
    if(!isEmpty()&&i-1!=0)
   {if(2*N+2>=count())
    {
        Max_index=2*N+1;
    }
    else{
     Max_index=find(max(get(2*N+1),get(2*N+2)));}
    while(get(Max_index)>get(N)&&(2*N+1<count()||2*N+2<count()))
    {
        int temp=get(N);
        edit(N,get(Max_index));
        edit(Max_index,temp);
        N=Max_index;
        if(2*N+1>=count())
        {break;}
        if(2*N+2>=count())
        {break;}
        Max_index=find(max(get(2*N+1),get(2*N+2)));}
}
cout<<endl;
}
int Heap::Max(){
    return get(0);
}
void Heap::show_heap(){
    print();
}
bool Heap::isEmpty()
{
return lastIndex==-1;
}
void Heap::insert(int value){
    if(!isFull())
    {
        append(value);
        int i=find(value);
        int parent_index=(i-1)/2;
        while(get(parent_index)<get(i)&&i>0)
        {
            int temp=get(i);
            edit(i,get(parent_index));
            edit(parent_index,temp);
            i=find(value);
            parent_index=(i-1)/2;
        }
    }
}
Heap::Heap(int cap){
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
void Heap::halfArray()
{
    int *temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
void Heap::doubleArray()
{
    int *temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void HeapSort(int a[],int len)
{
    Heap H1(len);
    for(int i=0; i<len; i++)
    {
        H1.insert(a[i]);
    }
    for(int i=len-1; i>=0; i--)
    {
        a[i]=H1.Max();
        H1.remove();
    }
}