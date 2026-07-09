#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t,nrp,x;
    f>>t;
    for (int i=1; i<=t; ++i)
    {
        f>>nrp;
        int s=0;
        for (int j=1; j<=nrp; ++j)
        {
            f>>x;
            s=s^x;
        }
        if (s==0) g<<'DA\n';
             else g<<'NU\n';
    }
    f.close(); g.close();
    return 0;
}
