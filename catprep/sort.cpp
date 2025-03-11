#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }    
};

Node *merge(Node *a, Node *b){

    if (a == NULL)
    {
        return b;
    }else if (b == NULL)
    {
        return a;
    }
    
    Node *c;

    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    
    
    return c;

}


Node *midPoint(Node *head){

    if(head == NULL || head->next == NULL)
        return head;

    Node *fast = head;
    Node *slow = head;
    while (fast !=NULL || fast->next !=NULL)
    {
        fast = fast->next;
        if(fast->next == NULL)
            break;

        fast = fast->next;
        slow = slow->next;
    }
    return slow;

}

Node *mergeSort(Node *head){

    if(head == NULL || head->next == NULL)
        return head;

    Node *mid = midPoint(head);
    Node *a = head;
    Node *b = mid->next;

    

    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    Node *c = merge(a, b);

    return c;

}