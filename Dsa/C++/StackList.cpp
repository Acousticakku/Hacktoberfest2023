#include"SLL.cpp"
class stack:private SLL{
public:
stack();
void push(int);
void pop();
int peek();
void reverse(stack &);
bool empty();
void operator=(stack &);
bool Palindrome(int);
};
bool stack::Palindrome(int number)
{int i,count=0;
    for(i=number;i>0;i/=10){count++;}
stack Aux;
i=number;
while(i)
{
    Aux.push(i%10);
    i=i/10;
}
while(number)
{
    if(number%10==Aux.peek()){
        Aux.pop();
        number=number/10;
    }
    else{
        return false;
    }
}
return true;
}
void stack::operator=(stack &s2)
{
SLL::operator=(s2);
}
bool stack::empty(){
node* ptr=get_start();
if(get_start()!=NULL){
    return false;
}
else{
    return true;
}
}
void stack::reverse(stack &s1){
    stack temp;
    while(!s1.empty())
    {
        temp.push(s1.peek());
        s1.pop();
    }
    s1=temp;
}
int stack::peek(){
    return (get_start())->data;
}
void stack::push(int data){
    In_Beginnings(data);
}
void stack::pop(){
    del_Beginnings();
}
stack::stack():SLL(){}