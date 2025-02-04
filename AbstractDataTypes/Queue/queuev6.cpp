#include <iostream>
using namespace std;
template <typename T>
struct Queue
{
    int capacity;
    T *queue;
    int front;
    int rear;
    int siz;
    Queue(int cap)
    {
        capacity = cap;
        front = rear = -1;
        siz = 0;
        queue = new T[capacity];
    }
    bool isEmpty()
    {
        return siz == 0;
    }
    bool isFull()
    {
        return siz == capacity;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        cout << "The removed element is " << queue[front] << endl;
        front++;
        siz--;
    }
    int count()
    {
        return siz;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << "Element at i=" << i << " " << queue[i] << endl;
        }
    }
    void enqueue(T val)
    {
        if (isFull())
        {
            T *newArray = new T[capacity * 2];
            for (int j = 0; j < capacity; j++)
            {
                newArray[j] = queue[j];
            }
            delete[] queue;
            queue = newArray;
            capacity = capacity * 2;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = val;
        siz++;
    }
    T peek()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return queue[front];
    }
};
int main()
{
    Queue<double> *q = new Queue<double>(5); // Queue q(5);
    cout << "Adding elements" << endl;
    q->enqueue(10); // q.enqueue();
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    cout << q->count() << endl;
    q->enqueue(66);
    q->display();
    q->dequeue();
    q->dequeue();
    q->display();
    cout << q->peek() << endl;
    return 0;
}
