#include <iostream>

using namespace std;


class Train
{
    private:
        double 
            mass,
            speed,
            x;
    public:
        Train(double m);
        void move(double dt);
        void accelerate(double dp);
        double getX() const;
};


Train::Train(double m)
{
    mass = m;
    speed = 0;
    x = 0; 
}

void Train::move(double dt)
{
    x += speed * dt;
}

void Train::accelerate(double dp)
{
    speed += dp / mass;
}

double Train::getX() const
{
    return x;
}


int main(int argc, char *argv[])
{ 
    Train t(10);
    t.accelerate(1); // Скорость стала 0.1
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.accelerate(-2); // Скорость стала -0.1
    t.move(3);
    cout << "Current X: " << t.getX() << endl;
}