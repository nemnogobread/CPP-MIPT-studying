#include <iostream>
#include <vector>

using namespace std;

class SpacePort
{
    private:
        vector<bool> docks;
    public:

    SpacePort(unsigned int size)
    {
        for (int i = 0; i < size; i++)
        {
            docks.push_back(false);
        }
    }

    bool requestLanding(unsigned int dockNumber)
    {
        if (dockNumber > docks.size() - 1)
            return false;
        else if (docks[dockNumber])
            return false;
        else
        {
            docks[dockNumber] = true;
            return true;
        } 
    }

    bool requestTakeoff(unsigned int dockNumber)
    {
        if (dockNumber > docks.size() - 1)
            return false;
        else if (docks[dockNumber])
        {
            docks[dockNumber] = false;
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;
    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;
}