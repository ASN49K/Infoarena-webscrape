#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a,b,c;
    f>>a>>b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;

    }
    g<<a;

    return 0;
}
