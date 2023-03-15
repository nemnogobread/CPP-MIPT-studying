#include <iostream>
#include "Train.h"

using namespace std;

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