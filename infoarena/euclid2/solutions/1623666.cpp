#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long n,a,b;
int main()
{

    f>>n;

    while(f>>a>>b)
    {
        int r;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
