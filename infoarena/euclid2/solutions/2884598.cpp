#include <fstream>
#include <iostream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    long long int t,a,b;
    f>>t;
    for(int i=1; i<=t; i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            long long int r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
