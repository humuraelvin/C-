#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node() {}
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template <typename T>
void display(Node<T> *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next; 
    }
    cout << "NULL" << endl;
}

int main()
{
    Node<int> *n1 = new Node<int>(15); 
    Node<int> *n2 = new Node<int>(20); 
    Node<int> *n3 = new Node<int>(30); 
    Node<int> n4(40);

    n1->next = n2;  
    n2->next = n3;  
    n3->next = &n4; 

    display(n1);



    return 0;
}
