#include<iostream>
#include<string>
using namespace std;


struct Node
{
    int data;
    Node *next;
};


bool hasLoop(Node *head){

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
        
    }
    return false;
}

Node *createNode(int value){

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    return newNode;

}

int main(){


    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);


    if (hasLoop(head))
    {
        cout<<"The linked list has a loop"<<endl;
    }else{
        cout<<"No loop has been detected"<<endl;
    }
    
    //Added a loop
    head->next->next->next->next->next = head->next;

    if (hasLoop(head))
    {
        cout << "The linked list has a loop" << endl;
    }
    else
    {
        cout << "No loop has been detected" << endl;
    }
}
