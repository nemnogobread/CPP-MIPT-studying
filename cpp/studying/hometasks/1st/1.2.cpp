#include <iostream>
using namespace std;

bool is_simple(int n);

int main ( ) 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if ( is_simple(i) )
            cout << i << ' ';
    }
    cout << endl;
    return 0;
}

bool is_simple(int n)
{
    for (int i = 2; i<n; i++)
        if ( n%i == 0 )
            return false;
    return true;
}
