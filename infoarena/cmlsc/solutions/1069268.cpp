#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 1025

using namespace std;

unsigned a,b,x[Nmax],y[Nmax],pd[Nmax][Nmax],i,j,l=0,len;
vector<unsigned> sol;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>a>>b;
    for(i=1;i<=a;i++)f>>x[i];
    for(i=1;i<=b;i++)f>>y[i];
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            if(x[i]==y[j])
            {
                if(j==1)
                    pd[i][j]=1+pd[i-1][j];
                else
                    pd[i][j]=1+pd[i-1][j-1];
                sol.push_back(x[i]);
            }
            else
            {
                if(j==1)
                    pd[i][j]=pd[i-1][j];
                else
                    pd[i][j]+=pd[i][j-1];
            }
            l = max(l,pd[i][j]);
        }
    }
    g<<l<<'\n';
    len = sol.size();
    for(i=0;i<len;i++)g<<sol[i]<<' ';
    return 0;
}
