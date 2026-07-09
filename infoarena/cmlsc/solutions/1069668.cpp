#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 1025

using namespace std;

unsigned a,b,pd[Nmax][Nmax],pdc[Nmax][Nmax],i,j,l=0,len,xi,yj;
char x[Nmax],y[Nmax];
vector<char> sol;
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
                pd[i][j]=1+pd[i-1][j-1];
                pdc[i][j]=1;
            }
            else
            {
                if(pd[i-1][j]>pd[i][j-1])
                {
                    pd[i][j]=pd[i-1][j];
                    pdc[i][j]=2;
                }
                else
                {
                    pd[i][j]=pd[i][j-1];
                    pdc[i][j]=3;
                }
            }
            if(pd[i][j]>l)
            {
                l = pd[i][j];
                xi=i;yj=j;
            }
        }
    }

    while(pd[xi][yj]!=0)
    {
        if(pdc[xi][yj]==1)
        {
            sol.push_back(x[xi]);
            xi--;
        }
        if(pdc[xi][yj]==2)
        {
            sol.push_back(y[yj]);
        }
        yj--;
    }
    g<<l<<'\n';
    len = sol.size();
    for(i=len;i>0;i--)g<<sol[i-1]<<' ';
    return 0;
}
