#include <iostream>
using namespace std;

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



void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

Node* userData(){
    int data;

    cout<<"Add a number to LL or -1 to exit"<<endl;

    cin>>data;
    Node *head = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
        }else
        {
            n -> next = head;
            head = n;
        }
        cin>>data;
        
    }
    return head;
    
}

int main()
{

    Node *head = userData();
    display(head);

    return 0;
}