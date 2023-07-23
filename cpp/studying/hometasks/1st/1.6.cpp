#include <iostream>
using namespace std;

unsigned long long int factorial(unsigned int n);

int main()
{
    unsigned int n;
    cin >>n;
    cout << factorial(n) << endl;
    return 0;
}

unsigned long long int factorial(unsigned int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n-1);
}