#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 1025

using namespace std;

unsigned a,b,pd[Nmax][Nmax],pdc[Nmax][Nmax],l=0,len,xi,yj;
char x[Nmax],y[Nmax];
vector<char> sol;

void rezolva(unsigned i, unsigned j)
{
    if(i==0 || j==0)
        return;
    if(pdc[i][j]==1)
    {
        l++;
        sol.push_back(x[xi]);
        rezolva(i-1,j-1);
    }
    else if(pdc[xi][yj]==2)
    {
        rezolva(i-1,j);
    }
    else
        rezolva(i,j-1);
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    unsigned i,j;
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
        }
    }

    rezolva(a,b);
    g<<l<<'\n';
    len = sol.size();
    for(i=len;i>0;i--)g<<sol[i-1]<<' ';
    return 0;
}
