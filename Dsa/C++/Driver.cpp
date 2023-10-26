#include <bits/stdc++.h>
using namespace std;
unsigned  long long  factorial(int m)
{
if(m<=1)
{
return 1; 
}
else{
    return m*factorial(m-1);
}
}
long long int uniquePaths(int m, int n) {
    m--;
    n--;
    int sum=m+n;
    cout<<m<<"==="<<n<<endl;
    cout<<"____"<<factorial(sum)<<"____"<<endl;
    cout<<"____"<<factorial(m)<<"____"<<endl;
    cout<<"____"<<factorial(n)<<"____"<<endl;
    return factorial(sum)/(factorial(m)*factorial(n));
    }
int main()
{
    cout<<uniquePaths(3,7)<<endl;
    cout<<uniquePaths(23,12);
}