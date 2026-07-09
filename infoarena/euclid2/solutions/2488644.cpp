#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
int main()
{
    f>>n;
    int r;
    while(f>>a>>b)
    {
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
}
