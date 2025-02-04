#include<iostream>
using namespace std;

template <typename T>
class Node
{
private:
    
public:
    T data;
    Node *next;
    Node(T x){
        this->data = x;
        next = NULL;
    }
};

template<typename T>
class Queue
{

    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }
    int count(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }
    void enqueue(T ele)
    {
        Node<T> *n = new Node<T>(ele);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    T front()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){

    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    cout<<q.front()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    q.enqueue(60);
    q.enqueue(70);

    q.display();
    q.dequeue();
    q.dequeue();

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;

    while (!q.isEmpty())
    {
        cout<<q.front()<<endl;
        q.dequeue();
    }

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}






