#include<iostream>
using namespace std;
struct node{
    int data;
    int vertex;
    node *next;
};
class adj_list{
node *start;
int pre_vertex;
public:
void set_vertex(int v){
    pre_vertex = v;
};
adj_list(){
    start = NULL;
}
node* get_start()
{return start;}
void add(int v,int d){
    node *n=new node;
    n->vertex=v;
    n->data=d;
    n->next=start;
    start=n;
}
void del(){
    node *ptr=start;
    start=ptr->next;
    delete ptr;
}
~adj_list(){
    while(start)
    {
        del();
    }
}
void print(){
   node *ptr=start;
   cout<<pre_vertex<<':'<<endl;
   while(ptr!=NULL)
   {
    cout<<" "<<ptr->vertex<<'('<<ptr->data<<')';
    ptr=ptr->next;
   }
   cout<<endl;
}
};
class Graph{
    int v_count;
    adj_list *arr;
    public:
    Graph();
    node* get_ad(int n){
        return arr[n].get_start();
    }
    int get_count() { return v_count; }
    void create_graph(int);
    void addEdge(int,int,int);
    ~Graph();
    void print_graph();
};
void Graph::print_graph(){
    for(int i=0;i<v_count;i++)
    {
        arr[i].print();
        cout<<endl;
    }
}
Graph::~Graph(){
    for(int i=0;i<v_count;i++){
    while(arr!=NULL){
        arr[i].del();
    }
    }
}
void Graph::addEdge(int v,int u,int d)
{
    arr[v].add(u,d);
}
Graph::Graph()
{
v_count = 0;
arr =NULL;
}
void Graph::create_graph(int u)
{
    int v, n,d1;
    v_count=u;
    arr=new adj_list[u];
    for(int i=0;i<v_count;i++)
    {
        arr[i].set_vertex(i);
        cout<<"\nHow many adjacent nodes of V"<<i<<":";
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cout<<"\nEnter vertex number: ";
            cin>>v;
            cout<<"\nEnter data to store: ";
            cin>>d1;
            arr[i].add(v,d1);
            arr[v].add(i,d1);
        }

    }

}

