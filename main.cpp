#include <iostream>
#include "scoped_ptr.h"
#include "shared_ptr.h"
using std::cout;
class Point
{
public:
    Point(int x, int y): x_(x), y_(y){}
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
private:
    int x_;
    int y_;

};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << p.x_ << ' ' << p.y_;
    return os;
}

int main()
{
    ScopedPtr<Point> p(new Point(2, 4));
    cout << *p << std::endl;
    SharedPtr<Point> ptr(new Point(1,2));
    cout << *ptr << std::endl;;

    SharedPtr<Point> ptr2;
    ptr2 = ptr;
    cout << *ptr2;
    return 0;
}
