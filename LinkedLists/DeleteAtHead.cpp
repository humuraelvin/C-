#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node *deleteAtHead(Node *head)
{
    if (head == nullptr)
        return nullptr; 

    Node *temp = head;
    head = head->next; 

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    cout << "Deleted " << temp->data << " at the head.\n";
    delete temp; 
    return head; 
}

void display(Node *head)
{ 
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40); 

    head->next = n2; 
    n2->next = n3;
    n3->next = n4;

    n2->prev = head;
    n3->prev = n2;
    n4->prev = n3;

    cout << "Original List:\n";
    display(head);

    head = deleteAtHead(head); 

    cout << "List after deletion:\n";
    display(head);

    return 0;
}
