#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,rest;

int main()
{
    int i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;
        f>>b;
        while (b)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        g<<a<<'\n';

    }
    return 0;
}
