#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int N,a,b,m;
int main()
{
    f>>N;
    for(;N>0;--N)
    {
        f>>a>>b;
        while(b!=0)
        {
            m=a%b;
            a=b;
            b=m;
        }
        g<<a<<'\n';
    }
}
