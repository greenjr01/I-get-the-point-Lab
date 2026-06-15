#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    private:
    double x;
    double y;

    public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double x_value, double y_value)
{
    x = x_value;
    y = y_value;
}

double operator-(const Point& other) const
{
    double x_diff = x - other.x;
    double y_diff = y - other.y;

    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

bool operator==(const Point& other) const
{
    return x == other.x && y == other.y;
}

bool operator!=(const Point& other) const
{
    return !(*this == other);
}

Point operator/(const Point& other) const
{
    double mid_x = (x + other.x) / 2;
    double mid_y = (y + other.y) / 2;

    return Point(mid_x, mid_y);
}

Point operator++()
{
    x++;
    return *this;
}

Point operator++(int)
{
    Point old_point = *this;
    y++;
    return old_point;
}

Point operator--()
{
    x--;
    return *this;
}

Point operator--(int)
{
    Point old_point = *this;
    y--;
    return old_point;
}

double& operator[](int index)
{
    if (index == 0)
    {
        return x;
    }

    return y;
}

friend ostream& operator<<(ostream& out, const Point& point);
friend istream& operator>>(istream& in, Point& point);
};
ostream& operator<<(ostream& out, const Point& point)
{
out << "(" << point.x << ", " << point.y << ")";
return out;
}

istream& operator>>(istream& in, Point& point)
{
char left_parenthesis;
char comma;
char right_parenthesis;
in >> left_parenthesis >> point.x >> comma >> point.y >> right_parenthesis;

return in;
}
int main()
{
Point p1(3.2, 9.8);
Point p2(5.5, -1.2);
cout << "Point 1: " << p1 << endl;
cout << "Point 2: " << p2 << endl;

cout << "Distance: " << p1 - p2 << endl;
cout << "Equal: " << (p1 == p2) << endl;
cout << "Not equal: " << (p1 != p2) << endl;
cout << "Midpoint: " << p1 / p2 << endl;

cout << endl;

cout << "Original p1: " << p1 << endl;

++p1;
cout << "After ++p1: " << p1 << endl;

p1++;
cout << "After p1++: " << p1 << endl;

--p1;
cout << "After --p1: " << p1 << endl;

p1--;
cout << "After p1--: " << p1 << endl;

cout << endl;

cout << "p1[0]: " << p1[0] << endl;
cout << "p1[1]: " << p1[1] << endl;

p1[0] = 10;
p1[1] = 20;

cout << "After changing p1[0] and p1[1]: " << p1 << endl;

cout << endl;

Point user_point;

cout << "Enter a point in the form (x, y): ";
cin >> user_point;

cout << "You entered: " << user_point << endl;

return 0;
}