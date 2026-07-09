#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

long int gdc(long int a, long int b)
{
    if(!b)
        return a;
    else
        return gdc(b,a%b);
}

int main()
{
    long int a,b;
    long int x;

    fi>>x;

    for(int i=1;i<=x;i++)
        {fi>>a>>b;
        fo<<gdc(a,b);
        fo<<'\n';}

    return 0;
}
