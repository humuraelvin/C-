#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void display(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

Node *deleteAtBegining(Node *head)
{

    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;

    head = head->next;

    delete temp;

    return head;
}

Node *deleteAtEnd(Node *head)
{

    Node *temp = head;

    while (head->next != NULL)
    {
        head = head->next;
    }

    delete head;

    return temp;
}

int main()
{
    Node *n1 = new Node(50);
    Node *n2 = new Node(15);
    Node *n3 = new Node(30);
    Node *n4 = new Node(27);
    Node *n5 = new Node(40);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    cout << "Original List:\n";
    display(n1);

    n1 = deleteAtEnd(n1);

    cout << "List after Deletion\n";

    display(n1);

    return 0;
}
