#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("nim.in");
ofstream g ("nim.out");
int t,n,x,s;
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n;
        s=0;
        for(int j=1;j<=n;++j)
        {
            f>>x;
           s=s^x;
        }
        if(s==0)
            g<<"NU\n";
        else g<<"DA\n";
    }
    return 0;
}
