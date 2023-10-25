#include<iostream>
#include "STACKTEMP.cpp"
using namespace std;
void bubbleSort(int A[],int size)
{
    int r,i,t;
    for(r=1;r<=size-1;r++)
    {
        for(i=0;i<=size-1-r;i++)
        {
            if(A[i]>A[i+1])
            {
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
    }
}
void modifiedBubbleSort(int A[],int size)
{
    int r,i,t;
    bool flag;
    for(r=1;r<=size-1;r++)
    {
        flag=false;
        for(i=0;i<=size-1-r;i++)
        {
            if(A[i]>A[i+1])
            {
                flag=true;
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
        if(flag==false)
            break;
    }
}
void insertionSort(int A[],int size)
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=A[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<A[j])
            {
                A[j+1]=A[j];
            }
            else
                break;
        }
        A[j+1]=temp;
    }
}
int minValueIndex(int A[],int size,int j)
{
    int i,min,minIndex;
    min=A[j];
    minIndex=j;
    for(i=j+1;i<=size-1;i++)
    {
        if(min>A[i])
        {
            min=A[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void selectionSort(int A[],int size)
{
    int t,i,minIndex;
    for(i=0;i<=size-2;i++)
    {
        minIndex=minValueIndex(A,size,i);
        t=A[i];
        A[i]=A[minIndex];
        A[minIndex]=t;
    }
}
int quick(int A[],int left,int right)
{
    int loc=left,t;
    while(left<right)
    {
        while(left<right && A[loc]<=A[right])
            right--;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[right];
        A[right]=t;
        loc=right;
        while(left<right && A[left]<=A[loc])
            left++;
        if(left==right)
            break;
        t=A[left];
        A[left]=A[loc];
        A[loc]=t;
        loc=left;
    }
    return loc;
}
void quickSort(int A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);
    if(loc>l+1)
        quickSort(A,l,loc-1);
    if(loc<u-1)
        quickSort(A,loc+1,u);
}
void quickSortLoop(int A[],int l,int u)
{
    int loc,i,j;
    Stack lower(10),upper(10);
    lower.push(l);
    upper.push(u);
    while(!lower.isEmpty())
    {
        i=lower.peek();
        j=upper.peek();
        loc=quick(A,i,j);
        lower.pop();
        upper.pop();
        if(loc>i+1)
        {
            lower.push(i);
            upper.push(loc-1);
        }
        if(loc<j-1)
        {
            lower.push(loc+1);
            upper.push(j);
        }
    }
}
void merge(int a[],int n1,int i1,int b[],int n2,int i2,int c[],int i3)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<n1&&j<n2;k++)
    {
        if(a[i+i1]<b[j+i2])
        {
            c[k+i3]=a[i+i1];
            i++;
        }
        else
        {
            c[k+i3]=b[j+i2];
            j++;
        }
    }
    while(i<n1)
    {
        c[k+i3]=a[i+i1];
        i++;
        k++;
    }
    while(j<n2)
    {
        c[k+i3]=b[j+i2];
        j++;
        k++;
    }
}
void mergepass(int SRC[],int size,int L,int DEST[])
{
    int j,mergeCount,index,R,S;
    mergeCount=size/(2*L);
    S=mergeCount*2*L;
    R=size-S;
    
    for(j=0;j<mergeCount;j++)
    {
        index=j*2*L;
        merge(SRC,L,index,SRC,L,index+L,DEST,index);
    }
    if(R<=L)
    {
        for(int i=0;i<R;i++)
            DEST[S+i]=SRC[S+i];
    }
    else
        merge(SRC,L,S,SRC,R-L,S+L,DEST,S);

}
void mergeSortLoop(int A[], int size)
{
    int L=1,B[size];
    while(L<size)
    {
        mergepass(A,size,L,B);
        mergepass(B,size,2*L,A);
        L=L*4;
    }
}
void merging(int A[],int l,int m,int u)
{
    int L[m-l+1],R[u-m],i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(i=0,j=0,k=l;i<m-l+1 &&j<u-m;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    while(i<m-l+1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,u);
        merging(A,l,m,u);
    }
}
