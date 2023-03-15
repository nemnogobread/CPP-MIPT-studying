#ifndef TRAIN_H
#define TRAIN_H

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

#endif