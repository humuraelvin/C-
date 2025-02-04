#include<iostream>
using namespace std;

class dynamicQueue
{
private:
    int *queue;
    int front;
    int rear;
    int capacity;
    int size;


    void resize(){
        int newCapacity = capacity * 2;
        int* newQueue = new int[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newQueue[i] = queue[(front + i) % capacity];
        }

        delete[]  queue;
        queue = newQueue;
        front = 0;
        rear = size;
        capacity = newCapacity;
        
    }

public:
   
   dynamicQueue(int initialCapacity = 2)
        :front(0), rear(0), size(0), capacity(initialCapacity){
            queue = new int[capacity];
        }

        ~dynamicQueue(){
            delete[] queue;
        }

        void enqueue(int element){
            
            if (size == capacity)
            {
                cout<<"Queue is full"<<endl;
                resize();
            }
            queue[rear] = element;
            rear = (rear + 1) % capacity;
            size++;

        }

        bool isEmpty() const{
            return size==0;
        }

        int dequeue(){
            if (isEmpty())
            {
                cout<<"Error!!, queue is empty"<<endl;
                return -1;
            }
            int element = queue[front];
            front = (front + 1) % capacity;
            size --;
                        
        }

        int getSize() const{
            return size;
        }

        int peek() const{
            if (isEmpty())
            {
                cout<<"Error, Queueu is empty"<<endl;
                return -1;
            }
            return queue[front];
        }

        void display() const{

            if (isEmpty())
            {
                cout<<"Error displaying element!: queue is empty"<<endl;
                return;
            }

            cout<<"Queue elements: ";
            for (int i = 0; i < size; i++)
            {
                cout<<queue[(front + i) % capacity]<<" ";
            }
            cout<<endl;
        }

};

int main(){

    dynamicQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Front element: " << queue.peek() <<endl;
    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}

