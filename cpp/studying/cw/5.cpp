#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Point
{
    protected:
        double x;
        double y;
    public:
        Point(double x, double y): x(x), y(y){}

        double get_x() const
        {
            return x;
        }

        double get_y() const
        {
            return y;
        }

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

class Polyline {
    private:
        vector <Point>  _Points; 
    public:
        // Конструктур и деструктор, если необходимы
        Polyline() = default;

        // Добавить очередную точку в ломаную
        void addPoint(double x, double y)
        {
            Point N(x , y);
            _Points.push_back(N);
        }

        // Получить количесто точек в ломаной в данный момент
        unsigned int getNumberOfPoints() const
        {
            return _Points.size();
        }

        // Получить длину ломаной в данный момент
        double getLength() const
        {
            unsigned int size = _Points.size();
            double dist = 0;
            for(unsigned int i = 1; i < size; ++i)
                dist += (_Points[i] - _Points[i-1]).dist(); 
            return dist;
        }
        
        // Получить x-координату i-ой точки ломаной, точки нумеруются в порядке добавления
        // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
        double getX(unsigned int i) const
        {
            return _Points[i].get_x();
        }

        // Получить y-координату i-ой точки ломаной, точки нумеруются в порядке добавления
        // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
        double getY(unsigned int i) const
        {
            return _Points[i].get_y();
        }
};

int main()
{
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    cout << "Length: " << p.getLength() << endl;
    cout << "Points:" << endl;
    for (unsigned int i = 0; i < p.getNumberOfPoints(); i++) 
    {
        cout << p.getX(i) << " " << p.getY(i) << endl;
    }
    return 0;
}