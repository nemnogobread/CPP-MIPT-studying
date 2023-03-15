#include <iostream>
#include "Train.h"

using namespace std;

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