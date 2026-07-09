#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int t,a,b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a,int b)
{
    if(!b)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>a;
        f>>b;
        g<<gcd(a,b)<<"\n";
    }
    return 0;
}
