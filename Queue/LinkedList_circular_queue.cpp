#include <iostream>
#include <climits>
using namespace std;
struct Node{
    
    int data;
    Node* next;
};

class queue{
    private:
    Node* front;
    Node* rear;
    
    public:
    queue(){
        front = NULL;
        rear = NULL;
    }
    
    
    void enqueue(int val){
        Node* newnode = new Node;
        newnode->data = val;
        newnode->next = NULL;
        
        if(rear == NULL){
            front = newnode;
            rear = newnode;
            rear->next = front;
            return;
        }
        rear->next = newnode;
        newnode->next = front;
        rear = rear->next;
        
    }
    void dequeue(){
        
        if(front == NULL){
            printf("underflow\n");
        }
        
        if(front == rear){
            front = rear = NULL;
        }
        else{
            Node* temp = front;
            front = front->next;
            rear->next = front;
            free(temp);
        }
    }
    int Front(){
        if(front == NULL){
            cout<<"Underflow!!!\n"<<endl;
            return INT_MIN;
        }
        
        return front->data;
    }
};
int main()
{
   queue q;
   q.enqueue(1);
   q.dequeue();
   q.dequeue();
   q.enqueue(2);
   q.enqueue(3);
   q.enqueue(4);
   q.enqueue(5);
   q.enqueue(6);
   q.enqueue(7);
   cout<<q.Front()<<endl;
   q.dequeue();
   cout<<q.Front()<<endl;
   q.dequeue();
   cout<<q.Front()<<endl;
   q.dequeue();
   cout<<q.Front()<<endl;
   q.dequeue();
   cout<<q.Front()<<endl;
   q.dequeue();
   cout<<q.Front()<<endl;
   q.dequeue();
   cout<<q.Front()<<endl;
   q.dequeue();
   
   
   
   return 0;
}
