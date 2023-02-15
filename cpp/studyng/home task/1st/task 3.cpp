#include <iostream>
using namespace std;

int sum(int a, int b);

int main()
{
    int n, res = 0;
    cin >> n;
    while (n)
    {
        int number = n % 10;
        res = sum(res, number);
        n /= 10;
    }
    cout << res << endl;
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}