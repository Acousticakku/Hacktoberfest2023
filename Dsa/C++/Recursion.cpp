#include<iostream>
#include<math.h>
using namespace std;
double Power(double x,double y)
{
  if(y==0)
  {return 1;}
if(y>0)
{
return x*Power(x,y-1);
}
else{
return (1/x)*Power(x,y+1);}
}
int HCF(int a,int b)
{if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return HCF(a%b, b);
    return HCF(a, b%a);
}
int fi_bo(int n)
{
  if(n>2)
  {
    return fi_bo(n-1)+fi_bo(n-2);
  }
  else{
  return n;}
}
void bin_N(int n)
{
  if(n)
  {
    bin_N(n/2);
    cout<<n%2;
  }
  
}
int digit_sum(int n)
{
if(n)
{
  return (n%10)+digit_sum(n/10);
}
return 0;
}
long int factorial(long int n)
{
  if(n>1)
  {
    return n*factorial(n-1);
  }
  else{
    return 1;
  }
}
int sqr_sumN_natural(int n)
{
if(n)
{
  return n*n + sqr_sumN_natural(n-1);}
else{return 0;}
}
int sumN_natural_even(int n)
{
if(n)
{return 2*n + sumN_natural_even(n-1);}
else{return 0;}
}
int sumN_natural_odd(int n)
{
if(n)
{return 2*n-1 + sumN_natural_odd(n-1);}
else{return 0;}
}
int sumN_natural(int n)
{
if(n)
{return n + sumN_natural(n-1);}
else{return 0;}
}
void natural_no(int n)
{
if(n>0)
  {natural_no(n-1);}
else{
    return ;
}
cout<<n<<" ";
}
void re_natural_no(int n)
{
if(n)
  {cout<<n<<" ";
    natural_no(n-1);}
}
void odd_no(int n)
{
    if(n)
    {
      odd_no(n-1);
      cout<<2*n-1<<" ";
    }
    
}
void re_odd_no(int n)
{
    if(n)
    {
      cout<<2*n-1<<" ";
      re_odd_no(n-1);
    }
    
}
void even_no(int n)
{
    if(n)
    {
      even_no(n-1);
      cout<<2*n<<" ";
    }
    
}
void re_even_no(int n)
{
    if(n)
    {
      if(n%2==0)
         cout<<n<<" ";
      re_even_no(n-1);
    }
    
}
void rsq_no(int n)
{
    if(n)
    {
      cout<<n*n<<" ";
      rsq_no(n-1);
    }
    
}
void sq_no(int n)
{
    if(n)
    {
      sq_no(n-1);
      cout<<n*n<<" ";
    }
    
}
void cube_no(int n)
{
    if(n)
    {
      cube_no(n-1);
      cout<<n*n*n<<" ";
    }
    
}
void re_cube_no(int n)
{
    if(n)
    {
      cout<<n*n*n<<" ";
      re_cube_no(n-1);
    }
    
}