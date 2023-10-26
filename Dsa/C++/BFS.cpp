#include "graphmatrix.cpp"
#include "QueueArrays.cpp"
#include "graphlist.cpp"
using namespace std;
void bfs_for_matrix(graphM G, int S)
{
int q,n;
Queue Q(6);
Q.enqueue(S);
bool V[G.get_v_count()];
V[S]=true;
while(!Q.underflow())
{
     n=Q.get_front();
    cout<<" V"<<n;
    Q.dequeue();
    Array *a=G.r_adj_node(n);
    for(int i=0;i<5;i++)
    {
         q=a->get(i);
        if(V[q]==false)
        {
            Q.enqueue(q);
            V[q]=true;
        }
    }
}
}
void List_bfs(Graph G,int S)
{
    
int q,n;
Queue Q(G.get_count());
Q.enqueue(S);
bool V[G.get_count()];
V[S]=true;
while(!Q.underflow())
{
     n=Q.get_front();
    cout<<" V"<<n;
    Q.dequeue();
    node *a=G.get_ad(n);
    while(a!=NULL)
    {
         q=a->vertex;
        if(V[q]==false)
        {
            Q.enqueue(q);
            V[q]=true;
        }
        a=a->next;
    }
}
}
/*/int n,u,i;
    bool status[G.getVCount()];
    Queue Q(G.getVCount());
    Q.insert(s);
    status[s]=true;
    while(!Q.isEmpty())
    {
        n=Q.getFront();
        cout<<"  V"<<n;
        Q.del();
        DynArray adjacent=G.adjacentNodes(n);
        for(i=0;i<adjacent.count();i++)
        {
            u=adjacent.get(i);
            if(status[u]==false)
            {
                Q.insert(u);
                status[u]=true;
            }
        }
    }/*/