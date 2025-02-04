#include<iostream>
using namespace std;

class Student
{
private:
    /* data */

public:
    int code;
    string name;
    string school;
    int age;
    Student *next;

    Student(){}
    Student(int c, string nm, string sch, int a){
        code = c;
        name = nm;
        school = sch;
        age = a;
        next = NULL;
    }

};

void display(Student *head){
    while (head!=NULL)
    {
        cout<<head->code<<" "<<head->name<<" "<<head->school<<" "<<head->age<<"->";
        head=head->next;
    }

    cout<<"NULL";
    
}

int main(){

 Student *s1 = new Student(10, "Mary", "RCA", 12);
 Student *s2 = new Student(11, "Kagabo", "RCA", 13);
 Student *s3 = new Student(12, "Peter", "RCA", 14);

 s1->next=s2;
 s2->next=s3;
 
 display(s1);

return 0;
}

