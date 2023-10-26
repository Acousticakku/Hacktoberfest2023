#include <iostream>
using namespace std;
struct node{
    char data;
    node *right;
    node *left;};
class BST
{
private:
node *root;
node* min_right(node *);
node* del(char,node*);
bool srch(char,node *ptr);
public:
BST();
void insert(char);
void preorder(node *ptr=NULL);
void in_order(node *ptr=NULL);
void post_order(node *ptr=NULL);
void delete_node(char);
bool search(char);
~BST();
};
BST::~BST(){
while(root)
 {del(root->data,root);}
}

bool BST::search(char element)
{
return srch(element,root);
}
bool BST::srch(char element,node *ptr)
{
    if(ptr==NULL)
    {
        return false;
    }
    else if(ptr->data==element)
    {
        return true;
    }
    else if(ptr->data>element)
    {
       return srch(element,ptr->left);
    }
    else{
       return srch(element,ptr->right);
    }
}
void BST::delete_node(char element){
root=del(element,root);
}
node* BST::min_right(node * r)
{
if(r->left==NULL)
{
return r;
}
else{
    return min_right(r->left);
}
}
node* BST::del(char element,node *ptr){
if(ptr->data==element)
{
    if(ptr->left==NULL&&ptr->right==NULL)
    {
        delete ptr;
        return NULL;
    }
    if(ptr->left!=NULL&&ptr->right==NULL)
    {
        node* temp = ptr->left;
        delete ptr;
        return temp;
    }
    if(ptr->left==NULL&&ptr->right!=NULL)
    {
        node* temp = ptr->left;
        delete ptr;
        return temp;
    }
    if(ptr->left!=NULL&&ptr->right!=NULL)
    {
        char mini=min_right(ptr->right)->data;
        ptr->data=mini;
        ptr->right=del(mini,ptr->right);
        return ptr;
    }
}
else if(ptr->data>element)
{
   ptr->left=del(element,ptr->left);
   return ptr;
}
else{
   ptr->right=del(element,ptr->right);
   return ptr;
}
}
void BST::post_order(node* ptr){
    if(ptr==NULL)
    {
        ptr=root;
    }
    if(ptr->left)
    {
        post_order(ptr->left);
    }
    if(ptr->right)
    {
       post_order(ptr->right);
    }
    cout<<ptr->data<<" ";
}
void BST::in_order(node* ptr){
    if(ptr==NULL)
    {
        ptr=root;
    }
    if(ptr->left)
    {
        in_order(ptr->left);
    }
    cout<<ptr->data<<" ";
    if(ptr->right)
    {
       in_order(ptr->right);
    }
    
}
void BST::preorder(node* ptr){
    if(ptr==NULL)
    {
        ptr=root;
    }
    cout<<ptr->data<<" ";
    if(ptr->left)
    {
        preorder(ptr->left);
    }
    if(ptr->right)
    {
        preorder(ptr->right);
    }
}
BST::BST(){
    root=NULL;
}
void BST::insert(char value)
{
node *new_node=new node;
new_node->data=value;
new_node->left=NULL;
new_node->right=NULL;
if(root==NULL)
{
root=new_node;
}
else{
int flag=0;
node *prev=root;
node *ptr=root;
while(ptr!=NULL)
{
prev=ptr;
if(ptr->data>value)
{
    ptr=ptr->left;
    flag=0;
}
else{
    ptr=ptr->right;
    flag=1;
}
}
if(flag)
{
prev->right=new_node;
}
else
{prev->left=new_node;}
}

}