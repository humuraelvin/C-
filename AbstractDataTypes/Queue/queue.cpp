#include <iostream>
using namespace std;
int n = 100;
int queue[5], front = -1, rear = -1, size = 0;
bool isEmpty()
{
    return size == 0;
}
bool isFull()
{
    return size == n; // or return rear = n-1
}
void enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
    }
    rear++;
    queue[rear] = val;
    size++;
}
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    cout << "The removed elmement is " << queue[front] << endl;
    front++;
    size--;
}
void display()
{
    if (front == -1)
    {
        cout << "queue is empty" << endl;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << "Element at index " << i << " is " << queue[i] << endl;
    }
}
int peek()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return (int)NULL;
    }
    return queue[front];
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    display();
    dequeue();
    display();
    cout << peek() << endl;
    return 0;
}