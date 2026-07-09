#include <iostream>
#include <fstream>
using namespace std;
int t;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        int ni,xorsum=0,x;
        f>>ni;
        for(int j=1;j<=ni;j++)
        {
            f>>x;
            xorsum^=x;
        }
        if(xorsum)
            g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}