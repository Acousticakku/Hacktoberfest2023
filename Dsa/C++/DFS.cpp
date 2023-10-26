#include "graphmatrix.cpp"
#include "graphlist.cpp"
using namespace std;
void DFS(graphM G, int S)
{
Stack Q(G.get_v_count());
Q.push(S);
bool V[G.get_v_count()];
V[S]=true;
while(!Q.isUnderflow())
{
    int n=Q.peek();
    cout<<" V"<<n;
    Q.pop();
    Array *a=G.r_adj_node(n);
    for(int i=0;i<5;i++)
    {
        int q=a->get(i);
        if(V[q]==false)
        {
            Q.push(q);
            V[q]=true;
        }
    }
    //Q.show();
}
}
void List_DFS(Graph G, int S)
{
    int q;
Stack Q(G.get_count());
Q.push(S);
bool V[G.get_count()];
V[S]=true;
while(!Q.isUnderflow())
{
    int n=Q.peek();
    cout<<" V"<<n;
    Q.pop();
    node *a=G.get_ad(n);
    while(a!=NULL)
    {
         q=a->vertex;
        if(V[q]==false)
        {
            Q.push(q);
            V[q]=true;
        }
        a=a->next;
    }
    //Q.show();
}
}