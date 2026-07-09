#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a , b , n;

int cmmdc(int a , int b)
{
    int r = 0;

    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;

}

int main()
{
    f >> n;

    for ( int i = 1 ; i <= n ; i++)
    {
        f >> a >> b;
        g << cmmdc(a , b) << '\n';
    }

    return 0;

}
