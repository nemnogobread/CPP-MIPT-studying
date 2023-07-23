#include <iostream>
using namespace std;

struct Box
{
    int price;
    int count;
};

void sort_buble (Box *a ,int n );

int main()
{
    int N, S, res_box_num = 0, res_sweet_count = 0 ;
    Box str[1000];
    cin >> N ;
    for (int i = 0; i < N; i++)
    {
        cin >> str[i].price >> str[i].count ;
    }
    cin >> S;

    sort_buble (str , N);

    int i = 0;
    while (i < N && str[i].price < S)
    {
        S -= str[i].price;
        res_sweet_count += str[i].count;
        res_box_num++;
        i++;
    }

    cout << endl << res_box_num << " " << res_sweet_count << endl ;
    
    return 0;
}

void sort_buble (Box *a , int n)
{
    bool is_sorted = true ;
    for ( int j=0 ; j<n-1 ; ++j ) 
    {
        for ( int i=1 ; i<n-j ; ++i )
        {
            if ( a[i].price < a[i-1].price )
            {
                swap ( a[i] , a[i-1] ) ;
                is_sorted = false ;
            }
        }
        if ( is_sorted == true )
            return ;
    }
}