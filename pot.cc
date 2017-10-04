#include <iostream>
using namespace std;

class Point
{
private :
            int xpos, ypos;
public :
           Point(int x, int y) : xpos(x),ypos(y) {}
       Point(const Point &copy) {
                   xpos=copy.xpos;
                   ypos=copy.ypos;
           }
          friend Point operator+(const Point &pos1,const Point &pos2);
};
Point operator+(const Point &pos1, const Point &pos2){
         Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
         return pos;
}

int main(){

    Point pos1(1,1);
    Point pos2(10,10);
    Point pos3=pos1+pos2;
    }
