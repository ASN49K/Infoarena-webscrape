#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,i,a,sol,j;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>n; sol=0;
        for(j=1;j<=n;j++)
        {
            fin>>a;
            sol^=a;
        }
    }
    if(!sol) fout<<"NU\n";
    else fout<<"DA\n";
    return 0;
}
