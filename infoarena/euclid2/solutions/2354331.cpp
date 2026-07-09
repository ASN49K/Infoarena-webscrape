#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;
void euclid_cmmdc(int a , int b)
{
    int c;
    while ( b )
    {
         c = a%b;
         a = b;
         b = c;
    }
    g << a <<"\n";
}

int main()
{
    f >> n ;
     for ( ; n-- ; n)
     {
         int a, b;
         f >> a >> b;
         euclid_cmmdc(a, b);
     }
    return 0;
}
