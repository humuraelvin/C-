#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }

};

class Circular
{
private:
    Node* head;

public:
   
   void insertAtBeginning(int value){
    Node* newNode= new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }else
    {
        Node* temp = head;
        while (temp->next != head)
        {
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        
    }
    
    cout<<"Inserted" << value << "to the list"<<endl;
   }

    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head->next == head)
       { 
            cout << "Deleted " << head->data << " from the beginning.\n";
            delete head;
            head = nullptr;
        }
        else
        {
           Node *temp = head;
            while (temp->next != head)
           { 
                temp = temp->next;
            }
           Node *toDelete = head;
           temp->next = head->next; 
           head = head->next;      
            cout << "Deleted " << toDelete->data << " from the beginning.\n";
           delete toDelete; 
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Circular Linked List: ";
        do
        {
            cout << temp->data << " ->";
            temp = temp->next;
        } while (temp != head); 
    }

    void search(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        int pos = 1;
        do
        {
            if (temp->data == key)
            {
                cout << "Element " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Element " << key << " not found in the list.\n";
    }

    void deleteByKey(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

       
        do
        {
            if (temp->data == key)
            {
                if (prev != nullptr)
                {
                    prev->next = temp->next; 
                }
                else
                {
                  
                    if (temp->next == head)
                    {
                        head = nullptr; 
                    }
                    else
                    {
                        Node *last = head;
                        while (last->next != head)
                        {
                            last = last->next;
                        }
                        last->next = temp->next;
                        head = temp->next;
                    }
                }
                cout << "Deleted element " << key << " from the list.\n";
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Element " << key << " not found in the list.\n";
    }
};

int main()
{
    Circular cll;

    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtBeginning(30);
    cll.display();

    cll.search(20);
    cll.search(40);

    cll.deleteAtBeginning();
    cll.display();

    cll.deleteByKey(10);
    cll.display();

    cll.deleteByKey(40);

    
    return 0;
}
