#include <iostream>
#include <limits.h>
using namespace std;

#define MAX 5
int q[MAX];

int f = -1;
int r = -1;

void enqueue(int val){
    
    if((r == MAX-1 && f == -1) || (f == (r+1)%MAX )){
        cout<<"Overflow!!\n";
        return;
    }
    
    if(f == -1 && r== -1) f = r = 0;
    
    else if(r == MAX-1 && f != 0 ) r = 0;
    
    else r++;
    
    q[r] = val;
}

int dequeue(){
    
    if(f == -1){
        printf("UNDERFLOW\n");
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

int main()
{
   for(int i = 1; i<=6; i++) enqueue(i);
   cout<<endl;
   for(int i=1; i<=6; i++) cout<<dequeue()<<" ";
   cout<<endl;
   enqueue(1);
   enqueue(2);
   enqueue(3);
   cout<<dequeue()<<" ";
   cout<<dequeue()<<" ";
   enqueue(5);
   
   
   return 0;
}
