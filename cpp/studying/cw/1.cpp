#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    protected:
        double _x;
        double _y;
        double _z;
    public:
        Point(double x, double y, double z): _x(x), _y(y), _z(z) 
        {
        
        }

        double x() const 
        {
            return _x;
        }
        
        double y() const 
        {
            return _y;
        }
        double z() const 
        {
            return _z;
        }
};

class Sphere
{
    private:
        Point center;
        double radius;

    public:
    // Конструктор сферы с центром в точке center и радиусом r
    Sphere(const Point& center, double r): center(center), radius(r) {}

    bool covers(const Point& p) const 
    {
        double presizion = 1e-6;
        double centreToPoint = sqrt((p.x() - center.x())*(p.x() - center.x()) + (p.y() - center.y())*(p.y() - center.y()) + (p.z() - center.z())*(p.z() - center.z()));
        return centreToPoint <= (radius + presizion); 
    }
};

int main()
{
    Point center(10.0, 10.0, 10.0);
    Sphere s(center, 0.5);
    // Создаём пару тестовых точек
    Point p1(10.1, 10.1, 10.1);
    Point p2(2, 2, 2);
    // Ожидаем, что первая точка внутри сферы
    cout << boolalpha << s.covers(p1) << endl;
    // Ожидаем, что вторая точка не попала внутрь сферы
    cout << boolalpha << s.covers(p2) << endl;
}