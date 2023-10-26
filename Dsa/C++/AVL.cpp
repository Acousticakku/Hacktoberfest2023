#include<iostream>
using namespace std;
struct node{
    node* left;
    int data;
    node* right;
    int height;
};
class AVL{
    private:
    node* root;
    protected:
    node* insert(node*,int);
    node* minValueNode(node*);
    node* deletion(node*,int);
    void inorderrec(node*);
    public:
     int hgt_m(node*);
    int BF(node*);
    node* lro(node*);
    node* rro(node*);
    void in(int);
    void del(int);
    void inorder();
    AVL();
};
void AVL::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<" "<<ptr->data<<"("<<BF(ptr)<<")";
        inorderrec(ptr->right);
    }
}
void AVL::inorder()
{
    inorderrec(root);
}
node* AVL::deletion(node* ptr,int data)
{      
    
    if (ptr == NULL) 
        return ptr; 

    if ( data < ptr->data ) 
        ptr->left = deletion(ptr->left, data);  
    else if( data > ptr->data ) 
        ptr->right = deletion(ptr->right,data); 
    else
    { if( (ptr->left == NULL) || (ptr->right == NULL) ) 
        { 
            node *temp = ptr->left ? ptr->left :ptr->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = ptr; 
                ptr = NULL; 
            } 
            else // One child case 
            *ptr = *temp; 
            free(temp);
        } 
    else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            node* temp = minValueNode(ptr->right); 
  
            ptr->data = temp->data; 
  
            // Delete the inorder successor 
            ptr->right = deletion(ptr->right,temp->data); 
        } 
    } 
    // If the tree had only one node then return 
    if (ptr == NULL) 
        return ptr; 
  
    
    ptr->height = 1 + max(hgt_m(ptr->left),hgt_m(ptr->right)); 
  
    
    int balance = BF(ptr);  
  
    // Left Left Case 
    if (balance > 1 && BF(ptr->left) >= 0) 
        return rro(ptr); 
  
    // Left Right Case 
    if (balance > 1 && BF(ptr->left) < 0) 
    { 
        ptr->left = lro(ptr->left); 
        return rro(ptr); 
    } 
  
    // Right Right Case 
    if (balance < -1 && BF(ptr->right) <= 0) 
        return lro(ptr); 
  
    // Right Left Case 
    if (balance < -1 && BF(ptr->right) > 0) 
    { 
        ptr->right = rro(ptr->right); 
        return lro(ptr); 
    } 
  
    return ptr; 
 
}
void AVL::del(int data)
{
    root=deletion(root,data);
}
void AVL::in(int data)
{
    root=insert(root,data);
}
node* AVL::insert(node* ptr, int data) 
{ 
    node *n;
    if(ptr==NULL)
    {
        n=new node;
        n->left=NULL;
        n->data=data;
        n->right=NULL;
        n->height=1;
        return n;
    }
    if (data < ptr->data) 
        ptr->left = insert(ptr->left,data); 
    else if (data > ptr->data) 
        ptr->right = insert(ptr->right, data); 
    else
        return ptr; 
    ptr->height = 1 + max(hgt_m(ptr->left), hgt_m(ptr->right)); 
    int balance = BF(ptr); 
    
    // Left Left Case 
    if (balance > 1 && data < ptr->left->data) 
        return rro(ptr); 
  
    // Right Right Case 
    if (balance < -1 && data > ptr->right->data) 
        return lro(ptr); 
  
    // Left Right Case 
    if (balance > 1 && data > ptr->left->data) 
    { 
        ptr->left = lro(ptr->left); 
        return rro(ptr); 
    } 
    // Right Left Case 
    if (balance < -1 && data < ptr->right->data) 
    { 
        ptr->right = rro(ptr->right); 
        return lro(ptr); 
    } 
    return ptr; 
        }
node* AVL::minValueNode(node *ptr)
{
    node* current = ptr; 
    while (current->left != NULL) 
        current = current->left;  
    return current;
}
int max(int a,int b)
{
    return(a>b?a:b);
}
node* AVL:: lro(node* ptr)
{
    node* A=ptr;
    node* B=ptr->right;
    node* C=B->left;
    A->right=C;
    B->left=A;
    A->height= max(hgt_m(A->left),hgt_m(A->right))+1;
    B->height= max(hgt_m(B->left),hgt_m(B->right))+1;
    return B;
}
node* AVL::rro(node* ptr)
{
    node* A=ptr;
    node* B=ptr->left;
    node* C=B->right;
    A->left=C;
    B->right=A;
    A->height= max(hgt_m(A->left),hgt_m(A->right))+1;
    B->height= max(hgt_m(B->left),hgt_m(B->right))+1;
    return B;
}
int AVL::BF(node* ptr)
{
   if(ptr==NULL)
        return 0;
    return hgt_m(ptr->left) - hgt_m(ptr->right);
}
int AVL::hgt_m(node* ptr)
{ if(ptr==NULL)
        return 0;
    return ptr->height;
}
AVL::AVL()
{ root=NULL;
}