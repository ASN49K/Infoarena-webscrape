#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid.in");
ofstream fout ("euclid.out");
int main()
{
    int t,x,y,r,i;
    fin>>t;
    for (i=1;i<=t;i++)
    {
        fin>>x>>y;
        while (y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    return 0;
}
