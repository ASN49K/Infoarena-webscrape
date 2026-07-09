#include <iostream>
#include <fstream>
using namespace std;
ifstream fisier_intrare("euclid2.in");
ofstream fisier_iesire("euclid2.out");
int n, x, y, sum;
int main()
{
fisier_intrare>>n;

for(int i = 1 ; i <= n ; i++)
{
    sum = 0 ;
    fisier_intrare>>x>>y;

    if( x < y )
    {
        sum = x ;
        x = y ;
        y = sum;
        sum = 0 ;
    }
    while ( y != 0)
    {
        sum = x % y ;
        x = y ;
        y = sum ;
    }
    fisier_iesire<< x << endl;
}

    return 0;
}
