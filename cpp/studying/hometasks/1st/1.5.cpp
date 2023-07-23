#include <iostream>
using namespace std;

void binary(unsigned int n);

int main()
{
    unsigned int n;
    cin >> n;
    binary(n);
    cout << endl;
    return 0;
}

void binary(unsigned int n)
{
    if (n < 2)
    {
        cout << n;
        return;
    }
    binary(n/2);
    cout << n%2;
    return;
}