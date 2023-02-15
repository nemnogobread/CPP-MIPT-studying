#include <iostream>
using namespace std;

unsigned int sum_of_numbers(unsigned int n);

int main()
{
    unsigned int n;
    cin >> n;
    cout << sum_of_numbers(n) << endl;
    return 0;
}

unsigned int sum_of_numbers(unsigned int n)
{
    unsigned int res = 0;
    while (n)
    {
        int number = n % 10;
        res = res + number;
        n /= 10;
    }
    return res;
}