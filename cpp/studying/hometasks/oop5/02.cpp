#include <iostream>
using namespace std;

class Vector2D {
    public:
        Vector2D(int x, int y) : x_{x}, y_{y} {}
        Vector2D() : Vector2D(0,0) {}

        int getX() const 
        {
            return x_;
        }
        int getY() const 
        {
            return y_;
        }

        void setX(int x)
        {
            x_ = x;
        }
        void setY(int y) 
        {
            y_ = y;
        }

        bool operator==(const Vector2D& rhs) const 
        {
            return x_ == rhs.x_ && y_ == rhs.y_;
                
        }

        bool operator!=(const Vector2D& rhs) const 
        {
            return !(*this == rhs);
        }

        Vector2D operator+(const Vector2D& rhs) const 
        {
            return {x_ + rhs.x_, y_ + rhs.y_};
        }

        Vector2D operator-(const Vector2D& rhs) const 
        {
            return {x_ - rhs.x_, y_ - rhs.y_};
        }

        Vector2D operator*(const int a) const 
        {
            return {x_ * a, y_ * a};
        }

    private:
        int x_;
        int y_;

    friend Vector2D operator*(int lhs, const Vector2D& rhs);
    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
    friend std::istream& operator>>(std::istream& stream, Vector2D &v);
};

Vector2D operator*(int lhs, const Vector2D& rhs) 
{
    return {lhs * rhs.x_, lhs * rhs.y_};
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v) 
{
    stream << "(" << v.x_ << "; " <<  v.y_ << ")";
    return stream;
}

std::istream& operator>>(std::istream &stream, Vector2D &v)
{
    stream >> v.x_ >> v.y_;
    return stream;
}


int main() 
{
    Vector2D v1;
    cin >> v1;
    cout << v1 << endl;

    Vector2D v2;
    cin >> v2;
    cout << v2 << endl;

    cout << boolalpha << (v1 == v2) << endl;
    cout << boolalpha << (v1 != v2) << endl;

    Vector2D v3 = v1 - v2;

    cout << v3 << endl;
    cout << v3 * 42 << endl;
    cout << 42 * v3 << endl;

    return 0;
}