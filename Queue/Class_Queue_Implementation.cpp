#include <iostream>
#include <climits>
using namespace std;
class queue{
    private:
    int* arr;
    int size = 5;
    int front = -1;
    int rear = -1;
    
    public:
    queue(int size = 5){
        arr = new int[size];
    }
    
    ~queue(){
        delete[] arr;
    }
    
    bool isEmpty(){
        return(front == -1);
    }
    bool isFull(){
        if(front == 0 && rear == size-1) return true;
        else return false;
    }
    void enqueue(int data){
        if(isFull()){
            printf("OverFlow!!!\n");
            return;
        }
        
        if(front == -1 && rear == -1) front = rear = 0;
        else{
            
            if(rear == size-1 && front != 0) rear = 0;
            else rear++;
        }
        arr[rear] = data;
    }
    void dequeue(){
        
        if(isEmpty()){
            printf("Underflow!!\n");
            return;
        }
        if(front == rear) front = rear = -1;
        else{
            if(front == size-1) front = 0;
            else front++;
        }
    }
    int Front(){
        if(isEmpty()){
            cout<<"Underflow!!"<<" ";
            return INT_MIN;
        }
        return arr[front];
        
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
   cout<<q.Front();
   
   
   
   return 0;
}
