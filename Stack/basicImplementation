#include <iostream>
#include <limits.h>
using namespace std;

#define MAX 100
int stk[MAX];
int top = -1;

void push(int a){
    if(top == MAX) {
        printf("Overflow");
        return;
    }
    stk[++top] = a;
    
    
}

int TOP(){
    
    if(top == -1){
        return INT_MAX;
    }
    return stk[top];
}

void pop(){
    
    if(top == -1){
        printf("underflow");
        return;
    }
    
    top--;
}
bool isEmpty(){
    
    if(top == -1) return true;
    else return false;
}
int main()
{
   push(1);
   push(2);
   push(3);
   push(4);
   
   while(!isEmpty()){
       cout<<TOP()<<" ";
       pop();
   }
   
   return 0;
}
