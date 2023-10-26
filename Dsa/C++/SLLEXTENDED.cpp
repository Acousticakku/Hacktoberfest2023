#include "SLL.cpp"
class SLL_E:public SLL{
public:
int count_items();
void reverse();
node* middle_node();
bool is_cycle();
int cycle_length();
void sort();
SLL_E operator+(SLL_E &);
SLL_E ADD(SLL_E &);
};
SLL_E SLL_E::ADD(SLL_E &temp)
{
int carry=0;
SLL_E third;
int sum;
node* first=temp.get_start();
node* second=get_start();
while(second!=NULL&&first!=NULL)
{
    sum=(first->data)+(second->data)+carry;
   if(sum>9)
   {
     carry=(sum)/10;
     sum=sum%10;
   }
   else{carry=0;}
   third.In_Beginnings(sum);
   first=first->next;
   second=second->next;
}
while(second!=NULL)
{
    sum=(second->data)+carry;
   if(sum>9)
   {
     carry=(sum)/10;
     sum=sum%10;
   }
   else{carry=0;}
   third.In_Beginnings(sum);
   second=second->next;
}
while(first!=NULL)
{
    sum=(first->data)+carry;
   if(sum>9)
   {
     carry=(sum)/10;
     sum=sum%10;
   }
   else{carry=0;}
   third.In_Beginnings(sum);
   first=first->next;
}
if(carry!=0)
{
   third.In_Beginnings(carry);
}
return third;
}
SLL_E SLL_E::operator+(SLL_E &Temp)
 {
SLL_E Third;
node* first=get_start();
node* sec=Temp.get_start();
while (first != NULL && sec != NULL) {
        if (first->data <= sec->data) {
            Third.In_Ends(first->data);
            first = first->next;
        } else {
            Third.In_Ends(sec->data);
            sec = sec->next;
        }
    }


while (first != NULL) {
        Third.In_Ends(first->data);
        first = first->next;
    }
    
    while (sec != NULL) {
        Third.In_Ends(sec->data);
        sec = sec->next;
    }
return Third;
 }
void SLL_E::sort() {
   int i=count_items();
   node* nxt=NULL;
   node* cur=NULL;
   node* prev=NULL;
   while(i--)
   {
      prev=NULL;
      cur=get_start();
      nxt=cur->next;
      while(nxt!=NULL)
      {
         if(cur->data>nxt->data)
         {
            if(prev==NULL)
            {
               set_start(nxt);
            }
            else{prev->next=nxt;}
            cur->next=nxt->next;
            nxt->next=cur;
            node* temp=cur;
            cur=nxt;
            nxt=temp;
         }
         prev=cur;
         cur=cur->next;
         nxt=nxt->next;
      }

   }
}
int SLL_E::cycle_length(){
   node* fast=(get_start())->next;
   node* slow=get_start();
   int count=0;
   while(fast!=slow&&is_cycle())
   {
      slow=slow->next;
      fast=(fast->next)->next;
      count++;
   }
   return count;
}
bool SLL_E::is_cycle()
{
   node* temp=get_start();
   int count=count_items();
   while(temp)
   {
      if(count==0&&temp!=NULL)
      {
         return true;
      }
      temp=temp->next;
      count--;
   }
   return false;
}
node* SLL_E::middle_node()
{
   node* end=(get_start()->next)->next;
   node* middle=get_start();
   while(end!=NULL)
   {
      middle=middle->next;
      if(end->next!=NULL)
      {end=(end->next)->next;}
      else
         {break;}
   }
   return middle;
} 
void SLL_E::reverse()
{
     node* prev=NULL;
     node* nex_t=get_start();
     node* current=NULL;
     while(nex_t)
     {
        prev=current;
        current=nex_t;
        nex_t=nex_t->next;
        current->next=prev;
     }
     set_start(current);
}
int SLL_E::count_items()
{int count=0;
node *temp=get_start();
while(temp)
{
count++;
temp=temp->next;
}
return count;
}