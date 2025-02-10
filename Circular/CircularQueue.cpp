#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularQueue
{
private:
    Node *front;
    Node *rear;

public:
    CircularQueue()
    {
        front = rear = NULL;
    }

    void enqueue(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = NULL;

        if (front == NULL)
        {
            front = rear = temp;
            rear->next = front;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
        delete temp;
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main()
{
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cq.dequeue();
    cq.display();

    return 0;
}
