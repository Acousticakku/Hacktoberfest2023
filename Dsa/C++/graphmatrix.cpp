#include<iostream>
#include "STACKTEMP.cpp"
using namespace std;
class graphM{
    private:
    int v_count,e_count;
    int **adj;
    public:
    void create_graphM(int,int);
    void adj_node(int);
    bool is_isolated(int);
    void print_graphM();
    Array* r_adj_node(int);
    int get_v_count()
    {
        return v_count;
    }
    ~graphM();
};
Array* graphM::r_adj_node(int node)
{
    Array *a=new Array(v_count+1);
    int k=0;
    for(int i=0;i<v_count;i++)
    {
        if(adj[node][i]==1)
        {
            a->append(i);
        }
    }
    return a;
}
graphM::~graphM()
{
    for(int i=0;i<v_count;i++)
        delete []adj[i];
    delete []adj;
}
bool graphM::is_isolated(int node)
{
    for(int i=1;i<v_count;i++)
    {
        if(adj[node][i]==1)
        {
           return false;
        }
    }
    return true;
}
void graphM::adj_node(int node)
{
    for(int i=1;i<=v_count;i++)
    {
        if(adj[node][i]==1)
        {
            cout<<'V'<<node<<"<->"<<'V'<<i<<endl;
        }
    }
}
void graphM::print_graphM()
{
    for(int i=0;i<v_count;i++)
    {
        for(int j=0;j<v_count;j++)
        {
            cout<<" "<<adj[j][i]<<" ";
        }
        cout<<endl;
    }
}
void graphM::create_graphM(int v,int e)
{
    int v1,u1;
    v_count = v;
    e_count = e;
    adj = new int*[v_count];
    for(int i=0;i<v_count;i++)
    {
        adj[i]=new int[v_count];
    }
    for(int i=0;i<v_count;i++)
        {for(int j=0;j<v_count;j++)
           { adj[i][j]=0;}}
    for(int k=1;k<=e_count;k++)
    {
        cout<<"\nEnter node numbers connecting edge:";
        cin>>u1>>v1;
        adj[u1][v1]=1;
        adj[v1][u1]=1;
    }
}

