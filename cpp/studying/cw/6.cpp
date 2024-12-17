#include <iostream>

using namespace std;

class Rational 
{
    protected:
        int numerator;
        int denominator;
    public:
        // Конструктор дроби, здесь a - числитель, b - знаменатель
        Rational(int a, int b): numerator(a), denominator(b) {}
        
        // - сложения двух дробей
        Rational operator + (const Rational& rational) 
        {
            return Rational(numerator * rational.denominator + denominator * rational.numerator, denominator * rational.denominator);
        }
        
        // - вычитания двух дробей
        Rational operator - (const Rational& rational) 
        {
            return Rational(numerator*rational.denominator - denominator*rational.numerator, denominator*rational.denominator);
        }
        
        // - умножения двух дробей
        Rational operator * (const Rational& rational) 
        {
            return Rational(numerator*rational.numerator, denominator*rational.denominator);
        }

        // - деления двух дробей
        Rational operator / (const Rational& rational) 
        {
            return Rational(numerator * rational.denominator, denominator * rational.numerator);
        }

        // - умножения дроби на целое число (должно работать при любом порядке операндов)
        Rational operator * (const int a) 
        {
            return Rational(numerator * a, denominator);
        }

        friend Rational operator * (const int a, const Rational& rational) 
        {
            return Rational(rational.numerator * a, rational.denominator);
        }

        int a() const { return numerator; }
        int b() const { return denominator; }
};

ostream& operator << (ostream &os, const Rational &rational)
{
    return os << rational.a() << "/" << rational.b() << endl;
}

int main() 
{
    Rational a(1, 2);
    Rational b(1, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;

    return 0;
}