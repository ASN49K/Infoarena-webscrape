#include <iostream>
#include <fstream>

using namespace std;
int T, a, b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

int main()
{
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    return 0;
}
