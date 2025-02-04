#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }

};

class Doubly
{
private:
    Node *head;

public:
   Doubly(){
    head = nullptr;
   }

    void insertAtBeginning(int value){
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head=newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head=newNode;
        }
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void deleteAtBeginning(int value){
        if (head == nullptr)
        {
            cout <<"List empty. Cannot delete"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        cout<<"Deleted "<<temp->data<<" at the beginning. \n";
        delete temp;
        
    }

    void display(){
        if (head == nullptr)
        {
            cout <<"List is empty"<<;
        }

        Node* temp = head;
        cout<<"Doubly Linked list"<<endl;
        
        while (temp != nullptr)
        {
            cout<<temp->data<< " ->";
            temp = temp->next;
        }
        
    }

    void search(int key){

        Node* temp = head;
        int pos = 1;

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout<<"Element " << key << "found at postion " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
            
        }
        cout<<"Element " << key << "not found in the list. "<<endl;

    }

    void deleteByKey(int key){
        Node *temp = head;

        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout<<"Element "<< key << "not found in the list"<<endl;
            return;
        }


        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }else{
            head= temp->next;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        
        cout<<"Deleted element " << key << "from the list. \n";
        delete temp;
        
    }


};

int main(){
    Doubly dll;

    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(30);
    dll.display();

    dll.search(20);
    dll.search(40);

    dll.deleteAtBeginning();
    dll.display();

    dll.deleteByKey(20);
    dll.display();

    dll.deleteByKey(40);
    
    return 0;

}



