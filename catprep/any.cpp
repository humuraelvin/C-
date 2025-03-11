#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};


Node *insertAtBeginning(Node *head, int data){

    Node *newNode = new Node(data);

    if (head !=NULL)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        newNode->prev = NULL;

    }
    return head;

}

void addNodeAfterPrev(Node *previous_node, int data){

    if (previous_node == nullptr)
    {
        cout<<"Previous node can't be null";
    }

    stuct Node *newNode = new Node();
    newNode->data = data;

    newNode->next = previous_node->next;
    newNode->prev = previous_node;

    if (previous_node->next !=null)
    {
        previous_node->next->prev = newNode;
    }

    previous_node->next = wN
    

    

}

Node *insertAtEnd(Node *head, int data){

    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;

    return head;

}

Node *delHead(Node *head){

    if(head == NULL)
        return NULL;

    Node *temp = head;

    head = head->next;

    if (head !=nullptr)
    {
        head->prev = nullptr;
    }

    delete temp;
    return head;

}

Node *delLast(Node *head){

    if (head == NULL)
        return NULL;

    if(head->next == NULL)
        delete head;
        return NULL;

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->prev->next = NULL;

    delete curr;

    return head;
    

}