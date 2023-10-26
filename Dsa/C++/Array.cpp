#include<iostream>
#include"BasicArray.cpp"
using namespace std;
class Array:public BasicArray
{
    public:
        Array(int);
        int greatest();
        int smallest();
        int search(int);
        void sort();
        int sum();
        float average();
        void rotateRightByOne();
        void removeDuplicate();
        void printArray();
        int secondLargest();
        void swapItems(int,int);
};
Array::Array(int cap):BasicArray(cap){ }
void Array::swapItems(int i,int j)
{
    int temp;
    if(i>=0&&i<count()&&j<count()&&j>=0)
    {
        temp=get(i);
        edit(i,get(j));
        edit(j,temp);
    }
}
int Array::secondLargest()
{
     int max;
    if(isEmpty())
    {
        cout<<"\nArray is empty"<<endl;
        return -1;
    }
    else if(count()<=1)
    {
cout<<"Array Have Only One element"<<endl;
    }
    max=get(0);
    int prev=get(0);
    for(int i=1;i<count();i++)
        {if(max<get(i))
            {prev=max;
            max=get(i);}}
    return prev;
}
void Array::removeDuplicate()
{
    for(int i=0;i<count();i++)
    {
        for(int j=i+1;j<count();j++)
        {
            if(get(i)==get(j))
            {
                del(j);
                j--;
            }
        }
    }
}
void Array::rotateRightByOne()
{
    int temp;
    int lastIndex;
    if(!isEmpty())
    {
        lastIndex=count()-1;
        temp=get(lastIndex);
        for(int i=lastIndex;i>0 ;i--)
            edit(i,get(i-1));
        edit(0,temp);
    }
}
float Array::average()
{
    return (float)sum()/count();
}
int Array::sum()
{
    int s=0;
    for(int i=0;i<count();i++)
        s=s+get(i);
    return s;
}
int Array::search(int data)
{
    for(int i=0;i<count();i++)
        if(get(i)==data)
            return i;
    return -1;
}
void Array::sort()
{
    int r, temp, i;
    for(r=1;r<=count()-1;r++)
    {
        for(i=0;i<=count()-1-r;i++)
        {
            if(get(i)>get(i+1))
            {
                temp=get(i);
                edit(i,get(i+1));
                edit(i+1,temp);
            }
        }
    }
}
int Array::smallest()
{
    int min;
    if(isEmpty())
    {
        cout<<"\nArray is empty"<<endl;
        return -1;
    }
    min=get(0);
    for(int i=1;i<count();i++)
        if(min>get(i))
            min=get(i);
    return min;
}
int Array::greatest()
{
    int max;
    if(isEmpty())
    {
        cout<<"\nArray is empty"<<endl;
        return -1;
    }
    max=get(0);
    for(int i=1;i<count();i++)
        if(max<get(i))
            max=get(i);
    return max;
}