#include <iostream>
using namespace std;

class Point{
private:
    int xCoord;
    int yCoord;
public:
    Point();
    Point(int y , int b);
    void display() const;
};


int main(){
    Point p1;
    Point p2 = Point (5 ,10);
   p1.display();
   p2.display();
    cout << endl;
    return 0;
}
void Point::display() const{
    cout << xCoord << endl;
    cout << yCoord << endl;
}
Point::Point() {
    xCoord = 5;
    yCoord = 6;
    return;
}
Point::Point(int y , int b){
    xCoord = y;
    yCoord = b;
    return ;
}
//member function implicit parameter
