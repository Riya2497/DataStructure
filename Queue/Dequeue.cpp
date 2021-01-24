#include <iostream>
#include <limits.h>
using namespace std;

#define MAX 5
int q[MAX];

int f = -1;
int r = -1;

bool isFull(){
    
    if((r == MAX-1 && f == 0) || f == (r+1)%MAX) return true; 
    else return false;
}

bool isEmpty(){
    
    if(f == -1) return true;
    else return false;
}

void enqueueF(int val){
    
    if(isFull()){
        cout<<"overflow!!!\n";
        return;
    }
    
    if(f == -1 && r == -1) f = r = 0;
    
    else{
        if(f == 0) f = MAX-1;
        else f--;
    }
    q[f] = val;
    cout<<"inserted front : "<<val<<endl;
}

void enqueueR(int val){
    
    if(isFull()){
        
        cout<<"Overflow!!!\n";
        return;
    }
    
    if(f == -1 && r == -1) f = r = 0;
    else{
        
        if(r == MAX-1) r = 0;
        else r++;
    }
    q[r] = val;
    cout<<"inserted rear : "<<val<<endl;
}

int dequeueF(){
    
    if(isEmpty()) {
        cout<<"Underflow ";
        return INT_MAX;
    }
    
    int val = q[f];
    
    if(f == r) f = r = -1;
    else{
        if(f == MAX-1) f = 0;
        else f++;
    }
    
    return val;
}

int dequeueR(){
    
    if(isEmpty()){
        
        cout<<"underflow!!! ";
        return INT_MAX;
    }
    
    int val = q[r];
    
    if(f == r) f = r = 0;
    else{
        
        if(r == 0) r = MAX-1;
        else r--;
    }
    
    return val;
}

int getFront(){
    
    if(isEmpty()){
        return INT_MAX;
    }
    else return q[f];
}

int getRear(){
    
    if(isEmpty()){
        return INT_MAX;
    }
    else return q[r];
    
}

int main()
{
   
   enqueueF(1);
   enqueueF(2);
   enqueueR(3);
   enqueueR(4);
   cout<<"deleted Front : "<<dequeueF()<<endl;
   cout<<"deleted rear : "<<dequeueR()<<endl;
   
   
   return 0;
}
