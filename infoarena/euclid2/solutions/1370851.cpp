#include <iostream>
#include <fstream>
using namespace std;
ifstream fisier_intrare("euclid2.in");
ofstream fisier_iesire ("euclid2.out");
int a , b ,num;
int main()
{


    fisier_intrare>>a>>b;
    if ( a < b)
    {
        while ( a != b )
        {
            num = b - a;
            b = a ;
            a = num ;
        }
    }
    else
    {
        while ( a != b )
        {
            num = a - b;
            a = b ;
            b = num ;
        }
    }
    fisier_iesire<<a;
    return 0;
}
