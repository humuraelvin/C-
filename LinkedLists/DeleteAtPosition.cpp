#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void display(Node* head){

    if (head == NULL)
    {
        return;
    }

    Node *temp = hed;

    while (temp)
    {
        cout<< temp->data << " -> ";

        temp = temp->next;
    }

}

Node *reverse(Node *head){

    Node *curr = head;

}

Node *curr = new Node(head);
Node *prev = new Node(NULL);
Node *nextNode = new Node(NULL);

Node *previous = NULL;
Node *n = NULL;
while (current != NULL)
{

    n = current->next;
    curr->next = previous;
    prev = current;
    nextNode = n;

}

    int main()
    {
        
  
    }