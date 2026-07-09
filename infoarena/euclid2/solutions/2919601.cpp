#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, a, b;

int Euclid(int a, int b)
{
    int dmax=1;

    for(int d=2; d<=a && d<=b; d++)
        if(a%d==0 && b%d==0)
            dmax=d;

    return dmax;
}

int main()
{
    f>>t;

    for(int i=1;i<=t;i++)
    {
        f>>a>>b;

        g<< Euclid(a,b)<<endl;

    }

    return 0;
}
