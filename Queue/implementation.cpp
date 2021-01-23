#include <iostream>
#include <limits.h>
using namespace std;

#define MAX 10

class Queue{
    
    int capacity;
    int size;
    int front ;
    int rear ;
    int count;
    int* arr;
    
    public:
    Queue(int size = MAX);
    ~Queue();
    
    void enqueue(int val);
    void dequeue();
    int peep();
    int getSize();
    bool isEmpty();
    bool isFull();
    
};

Queue:: Queue(int size){
    
    arr = new int[size];
    capacity = size;
    front = -1;
    rear = -1;
    count = 0;
    
}

Queue :: ~Queue(){
    
    delete[] arr;
}
void Queue :: enqueue(int val){
    
    if(isFull()){
        printf("overflow!!!\n");
        return;
    }
    
    if(front == -1 && rear == 0) front = 0;
    rear = (rear+1)%capacity;
    arr[rear] = val;
    count++;
    
}
void Queue :: dequeue(){
    
    if(isEmpty()){
        printf("Underflow\n");
        return;
    }
    
    front = (front+1)%capacity;
    count--;
    
}

bool Queue :: isFull(){
    
    return (count == capacity);
}
bool Queue :: isEmpty(){
    
    return (count == 0);
}

int Queue :: peep(){
    
    if(isEmpty()){
        printf("Empty queue\n");
        return -1;
    }
    return arr[front];
}
int Queue :: getSize(){
    
    return count;
}
int main()
{
   Queue q (5);
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.enqueue(4);
   q.enqueue(5);
   q.enqueue(6);
   
   while(!q.isEmpty()){
       cout<<q.peep()<<" ";
       q.dequeue();
   }
   cout<<endl;
   q.dequeue();
   
   return 0;
}
