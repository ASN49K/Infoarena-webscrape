#include <iostream>
#include <fstream>
#include <algorithm>

///#include <tryhardmode>
///#include <GODMODE::ON>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int main()
{
    int t,n,i,j,x;
    fin>>t;
    while(t--)
    {
        int valid=0;
        fin>>n;
        for(i=1;i<=n;i++)
        {
            fin>>x;
            valid=valid^x;
        }
        if(valid==0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    return 0;
}
