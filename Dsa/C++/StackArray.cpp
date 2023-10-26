#include"BasicArray.cpp"
#include <string>
using namespace std;
class Stack:private BasicArray{
    private:
    int capacity;
    int top;
    bool isOperand(char);
public:
Stack(int);
void push(char);
void pop();
~Stack();
int isOverflow();
int isUnderflow();
void reverse();
void show();
int peek();
bool Palindrome(int);
string postfix(string);
string infix(string);
};
bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
}
string Stack::infix(string S)
{
int length =S.length();
Stack m(2*length);
for(int i=0;i<length;i++)
{
    if(isOperand(S[i]))
    {
        m.push(S[i]);
    }
    else{
        char s1=m.peek();
        m.pop();
        char s2=m.peek();
        m.pop();
        m.push('(');
        m.push(s2);
        m.push(S[i]);
        m.push(s1);
        m.push(')');
    }
    
}

}
string Stack::postfix(string S)
{
    string pf;
    int L=S.length();
    //cout<<L<<endl;
    Stack aux(L);
    for(int i=0;i<L; i++)
    {
        if(S[i]=='('||S[i]==')'||S[i]=='+'||S[i]=='-'||S[i]=='*'||S[i]=='/')
        {
            if(S[i]=='+'||S[i]=='-'||S[i]=='*'||S[i]=='/')
            {
                if(aux.isUnderflow())
                {
                    aux.push(S[i]);
                    
                }
                else if((S[i]=='*'||S[i]=='/')&&(aux.peek()=='+'||aux.peek()=='-'||aux.peek()=='/'||aux.peek()=='('))
                {aux.push(S[i]);
                }
                else if((aux.peek()=='*'||aux.peek()=='/')&&(S[i]=='+')){
                    while((!aux.isUnderflow())&&(aux.peek()!='+'||aux.peek()!='-'||aux.peek()!='(')){
                    if(aux.peek()!='('){pf+=aux.peek();}
                    aux.pop();}
                    aux.push(S[i]);
                   }
                else if((aux.peek()=='*'||aux.peek()=='/'||aux.peek()=='+')&&(S[i]=='-')){
                    while((!aux.isUnderflow())&&(aux.peek()!='-'||aux.peek()!='(')){
                    if(aux.peek()!='('){pf+=aux.peek();}
                    aux.pop();}
                    aux.push(S[i]);
                   }
                else if((aux.peek()=='*')&&(S[i]=='/')){
                    while((!aux.isUnderflow())&&(aux.peek()!='+'||aux.peek()!='-'||aux.peek()!='/'||aux.peek()!='(')){
                    if(aux.peek()!='('){pf+=aux.peek();}
                    aux.pop();}
                    aux.push(S[i]);
                    
                }
                else if((aux.peek()=='/')&&(S[i]=='+')){
                    while((aux.peek()!='+'||aux.peek()!='-')&&!aux.isUnderflow()){
                    if(aux.peek()!='('){pf+=aux.peek();}
                    aux.pop();}
                    aux.push(S[i]);
                    
                }
                else if((aux.peek()=='/')&&(S[i]=='-')){
                    while((aux.peek()!='-')&&!aux.isUnderflow()){
                    if(aux.peek()!='('){pf+=aux.peek();}
                    aux.pop();}
                    aux.push(S[i]);
                    }
                else if((aux.peek()=='+')&&(S[i]=='-')){
                    while((aux.peek()!='-')&&!aux.isUnderflow()){
                    if(aux.peek()!='('){pf+=aux.peek();}
                    aux.pop();}
                    aux.push(S[i]);
                    }
                else{
                    aux.push(S[i]);
                   
                }
            }
            else if(S[i]==')')
            {
                //aux.show();
 while(aux.peek()!='('&&!aux.isUnderflow())
 {pf+=aux.peek();
    aux.pop();}
    if(aux.peek()=='(')
    {aux.pop();}
        }
            else{
                aux.push(S[i]);
               
            }
        }
        else{
            pf+=S[i];
            
        }
    }
while(!aux.isUnderflow())
    {
       if(aux.peek()!='('){pf+=aux.peek();}
        aux.pop();
    } 
return pf;
}
int Stack::peek(){
    return get(top);
}
bool Stack::Palindrome(int number)
{int i,count=0;
    for(i=number;i>0;i/=10){count++;}
Stack Aux(count);
i=number;
while(i)
{
    Aux.push(i%10);
    i=i/10;
}
Aux.show();
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
void Stack::show(){
    print();
}
void Stack::reverse(){
    for(int i=0;i<=top/2;i++)
    {
         int temp=get(i);
        edit(i,get(top-i));
        edit(top-i,temp);
    }
}
int Stack::isOverflow(){
    if(isFull()){
       return 1;
    }
    return 0;
}
int Stack::isUnderflow(){
    if(isEmpty()){
        return 1;
    }
    return 0;
}
Stack::~Stack(){

}
void Stack::pop()
{
    del(top);
    top--;
}
void Stack::push(char data){
    append(data);
    top++;
}
Stack::Stack(int c):BasicArray(c)
{top=-1;
capacity=c;
}