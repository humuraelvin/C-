#include <iostream>
using namespace std;


class Rectangle
{
private:
    int width;
    int length;
public:
    Rectangle(){}
    Rectangle(int w, int l){
        width = w;
        length = l;
    }

    int area(){
        return width * length;
    }

    void setValues(int w, int l){
        width = w;
        length = l;
    }

    void setWidth(int w){
        width = w;
    }

};

 int main(){
    Rectangle recta;

    recta.setValues(10, 20);

    cout <<"The area is: " << recta.area() <<endl;

    Rectangle rectb;

    rectb.setValues(10, 30);

    cout <<"The area is: " << rectb.area() <<endl;

 }
