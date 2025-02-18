#include<iostream>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};


Date createDate(int year, int month, int day){

    Date d;
    d.year = year;
    d.month = month;
    d.day = day;
    return d;

}


void displayDate(const Date &d){

    cout<<"Date: "<<d.year <<"-"<<d.month<<"-"<<d.day<<endl;

}

int main(){

 Date today = createDate(2025, 2, 18);

 displayDate(today);

return 0;
}
