#include <iostream>
#include <limits.h>
using namespace std;

class Node{
    
    public:
    Node* next;
    int data;
    Node* prev;
    
};

class myStack{
    
    public:
    Node* head;
    Node* mid;
    int count;
};

myStack* createStack(){
    
    myStack* ms = new myStack();
    ms->count = 0;
    return ms;
}

void push(myStack* ms, int val){
    
    Node* newnode = new Node;
    newnode->data = val;
    newnode->prev = NULL;
    
    ms->count += 1;
    
    
    if(ms->count == 1){
        ms->mid = newnode;
    }
    else{
        
        newnode->next = ms->head;
        ms->head->prev = newnode;
        
        if(!((ms->count) & 1)){
            ms->mid = ms->mid->prev;
        }
    }
    
    ms->head = newnode;
    
}
int pop(myStack* ms){
    
    if(ms->count == 0){
        printf("Underflow\n");
        return -1;
    }
    
    Node* temp = ms->head;
    ms->head = temp->next;
    int val = temp->data;
    temp->next = NULL;
    
    
    ms->count -= 1;
    
    if(ms->head != NULL) ms->head->prev = NULL;
    
    if((ms->count) & 1) ms->mid = ms->mid->next;
    
    free(temp);
    return val;
}
int findMiddle(myStack* ms){
    
    if(ms->count == 0){
        return INT_MAX;
    }
    
    return ms->mid->data;
}
int main()
{
   myStack *ms = createStack();  
    push(ms, 11);  
    push(ms, 22);  
    push(ms, 33);  
    push(ms, 44);  
    push(ms, 55);  
    push(ms, 66);  
    push(ms, 77);  
  
   cout << "Item popped is " << pop(ms) << endl;  
   //cout << "Item popped is " << pop(ms) << endl;
   cout<<ms->head->data<<endl;
   cout << "Middle Element is " << findMiddle(ms) << endl;  
    
   return 0;
}
