#include <iostream>

using namespace std;
const float R = 8.31;

class GasHolder
{
    private:
        float pressure,
        capacity, 
        temperature;
    public:

    GasHolder(float v)
    {
        capacity = v;
        temperature = 273;
        pressure = 0;
    }

    ~GasHolder(){}

    void inject(float m, float M)
    {
        pressure += (m*R*temperature) / (M*capacity);
    }

    void heat(float dT)
    {
        pressure *= (temperature + dT) / temperature;
    }

    void cool(float dT)
    {
        if (temperature - dT < 0)
        {
            temperature = 0;
            pressure = 0;
        }
        else 
            pressure = (temperature - dT) / temperature;
    }

    float getPressure()
    {
        return pressure;
    }
};


int main()
{
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
}
