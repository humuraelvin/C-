#include <iostream>
using namespace std;


struct Rectangle
{
// private:
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

    void setWidth(int w){
        width = w;
    }

};

 int main(){
    Rectangle recta;

    

    recta.setWidth(40);
    recta.length = 10;

    cout <<"The area is: " << recta.area() <<endl;

    Rectangle rectb;

   

 }
