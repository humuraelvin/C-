#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() {}
    Node(int d)
    {

        data = d;
        next = NULL;
    }
};

Node *addAtTail(Node *head, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (head->next!=NULL)
        {
            head=head->next;
        }
        head->next=newNode;
    }
    return temp;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{

    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);
    Node *head = addAtTail(n1, 500);

    n1->next = n2;
    n2->next = n3;
    n3->next = &n4;

    display(n1);

    return 0;
}