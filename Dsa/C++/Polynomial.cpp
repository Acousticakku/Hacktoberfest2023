#include <iostream>
using namespace std;
struct np{
    int coff;
    int power;
    np *nxt;
};
class polynomial{
    np* f_term;
    public:
    polynomial();
    void add_term(int,int);
    polynomial operator+(polynomial &);
    void display_poly();
};
polynomial polynomial::operator+(polynomial &Extra)
{
    polynomial tmp;
    np *first=f_term;
    np *second=Extra.f_term;
    while(first!=NULL)
    {
        tmp.add_term(first->coff,first->power);
        first=first->nxt;
    }
    while(second!=NULL)
    {
        tmp.add_term(second->coff,second->power);
        second=second->nxt;
    }
    return tmp;
}
void polynomial::display_poly()
{
    np* first=f_term;
    while(first!=NULL)
    {
        if((first->power)!=0)
        {cout<<first->coff<<"x^("<<first->power<<")";}
        else{
            cout<<first->coff;
        }
        if(first->nxt!=NULL)
        {
            cout<<"+";
        }
        first=first->nxt;

    }cout<<endl;
}
void polynomial::add_term(int c,int p)
{
np* ptr=f_term;
while(ptr!=NULL)
{
if((ptr->power)==p)
{
     (ptr->coff)+=c;
     return;
}
ptr=ptr->nxt;
}
np *new_node= new np;
new_node->coff=c;
new_node->power=p;
ptr=f_term;
while(ptr!=NULL)
{
if((ptr->power)>p)
{
     new_node->nxt=ptr->nxt;
     ptr->nxt=new_node;
     return;
}
ptr=ptr->nxt;
}
new_node->nxt=f_term;
f_term=new_node;
}
polynomial::polynomial()
{
    f_term = NULL;
}
