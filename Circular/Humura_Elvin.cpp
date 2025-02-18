#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int code;
    string name;
    int age;
    Student *next;

    Student(int c, string n, int a)
    {
        code = c;
        name = n;
        age = a;
        next = NULL;
    }
};

class PriorityQueue
{
private:
    Student *front;

public:
    PriorityQueue()
    {
        front = NULL;
    }

    void enqueue(int code, string name, int age)
    {
        Student *temp = new Student(code, name, age);

        if (front == NULL || front->code > code)
        {
            temp->next = front;
            front = temp;
        }
        else
        {
            Student *curr = front;
            while (curr->next != NULL && curr->next->code < code)
            {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Student *temp = front;
        front = front->next;
        delete temp;
    }

    void display()
    {
        Student *temp = front;
        while (temp != NULL)
        {
            cout << "Code: " << temp->code << ", Name: " << temp->name << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(3, "Alice", 20);
    pq.enqueue(1, "Bob", 22);
    pq.enqueue(2, "Charlie", 21);

    pq.display();
    cout << "After dequeue:" << endl;
    pq.dequeue();
    pq.display();

    return 0;
}
