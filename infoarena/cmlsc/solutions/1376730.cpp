#include <iostream>
#include <fstream>
using namespace std;
ifstream fisier_intrare("cmlsc.in");
ofstream fisier_iesire("cmlsc.out");
int a[1024], b[1024] , c[1024] , m , n , sum = 0;
int main()
{
    fisier_intrare>> m >> n ;
    for (int i = 0 ; i < m ; i ++)
    {
        fisier_intrare>> a[i];
    }
    for (int i = 0 ; i < n ; i ++)
    {
        fisier_intrare>> b[i];
    }
    for ( int i = 0 ; i < m ; i++)
    {
        for ( int j = 0 ; j < n ; j++)
        {
            if ( a [i] == b[j] )
            {
                c[sum] = a[i] ;
                sum++;
                break;
            }
        }
    }
    fisier_iesire<<sum<<endl;
    for(int i = 0 ; i < sum ; i++)
    {
        fisier_iesire<<c[i]<<" ";
    }

    return 0;
}
