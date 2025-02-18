#include<iostream>
#include<iomanip>
using namespace std;


struct Student
{
    string name;
    int age;
    int rollNumber;
    float marks;
};

void displayStudents(const Student &s){

    cout<<s.rollNumber<<", "<< s.name<<", "<< s.age <<", "<<s.marks<<endl;

}

int main(){

    Student s1 = {"Mahoro Peace", 17, 202201, 90.4};
    Student s2 = {"Muhizi Brian", 17, 202202, 80.4};
    Student s3 = {"Juru Ethan", 17, 202203, 45.2};

    displayStudents(s1);
    displayStudents(s2);
    displayStudents(s3);

    return 0;

}
