#include <iostream>
using namespace std;

int queue[100], n = 100, front = -1, rear =  -1;

template<typename T>
struct Queue
{
    int front, rear, n;
    T *queue;
    Queue(int c){
        n = c;
        front = rear = -1;
        queue = new T;
    }
};


void enqueue(){

    T val;

    if (rear == n -1)
    {
        cout<<"Overflow."<<endl;
        return;
    }else
    {
        if (front == -1)
        {
            front = 0;

            rear++;
            queue[rear] = val;
        }

    }
    
}

void dequeue(){

    if (front == -1 || front > rear)
    {
        cout<<"Underflow/empty"<<endl;
        return;
    }
    front ++;
}


void display(){

    if (front == -1)
    {
        cout<<"QUEUE is empty"<<endl;
        return;
    }

    for (int i = front; i < rear; i++)
    {
        cout<<queue[i]<<" "<<endl;
    }
}

void peek(){

    if (front == -1)
    {
        cout<<"empty"<<endl;
        return;
    }
    cout<<queue[front]<<endl;

}

int main(){

    Queue<double> q(5);

}