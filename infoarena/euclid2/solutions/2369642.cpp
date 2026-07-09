#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;

int euclid( int a , int b )
{
    int c;
    while ( b )
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}


int main()
{
    f >> n ;
    while ( n-- )
    {
        int a, b;
         f >> a >> b ;
         g << euclid( a, b)<< "\n" ;
    }
    return 0;
}
