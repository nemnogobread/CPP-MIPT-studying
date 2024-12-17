#include <cmath>
#include <iostream>

using namespace std;

class Point
{
    protected:
        int x;
        int y;
    
    public:
        Point(int x, int y): x(x), y(y) {}

        Point operator+(const Point& a) const 
        {
            return Point(x + a.x, y + a.y);
        }

        Point operator-(const Point& a) const 
        {
            return Point(x - a.x, y - a.y);
        }

        double dist() const 
        {
            return sqrt(x * x + y * y);
        }
};

class Triangle
{
    private:
        Point a, b, c;
    public:
    // Создать треугольник из трёх точек
    Triangle(const Point& a, const Point& b, const Point& c): a(a), b(b), c(c) {}

    // Посчитать и вернуть периметр треугольника
    double perimeter() const
    {
        double ab = (a - b).dist();
        double bc = (b - c).dist();
        double ca = (c - a).dist();
        return ab + bc + ca;
    }
};

int main()
{
    Point a(0, 0), b(0, 5), c(5, 0);
    Triangle t(a, b, c);
    cout << t.perimeter() << endl;
    return 0;
}