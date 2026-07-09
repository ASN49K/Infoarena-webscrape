#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long T,a,b,i;
    f>>T;
    for (i=1; i<=T; i++)
    {
        f>>a>>b;
        while (a!=b)
        {
            if (a>b)
                a-=b;
            else
                b-=a;
        }
        g<<a<<'\n';
    }
    return 0;
}
