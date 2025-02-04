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
    if (head == NULL) // Correct the assignment to equality check
        return;

    Node *temp = head;

    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

Node *deleteAtEnd(Node *head)
{
    if (head == NULL) 
        return NULL;

    if (head->next == NULL) 
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    Node *secondLast = head;

    
    while (secondLast->next != NULL)
    {
        temp = secondLast;
        secondLast = secondLast->next;
    }

    
    temp->next = NULL;
    delete secondLast;

    return head;
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

    cout << "List after Deletion:\n";
    display(n1);

    return 0;
}
