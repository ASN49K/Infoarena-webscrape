#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    int r;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long long a,b,t;
    f>>t;
    for (int i=1; i<=t; i++)
    {
       f>>a>>b;
       g<<euclid(a,b)<< '\n' ;
    }
    return 0;
}
