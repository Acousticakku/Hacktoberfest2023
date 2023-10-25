#include"Array.cpp"
#include <string>
using namespace std;
class Stack:private BasicArray{
    private:
    int capacity;
    int top;
public:
Stack(int);
void push(int);
void pop();
~Stack();
int isOverflow();
int isUnderflow();
void show();
int peek();
};
int Stack::peek(){
    return get(top);
}

void Stack::show(){
    print();
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
void Stack::push(int data){
    append(data);
    top++;
}
Stack::Stack(int c):BasicArray(c)
{top=-1;
capacity=c;
}