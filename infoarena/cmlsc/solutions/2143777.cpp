#include <iostream>
#define NM 1025
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[NM],b[NM],lg[NM][NM],d[NM][NM],n,m;
void afisare(int i,int j)
{
    if(i>0 && j>0)
    {
        if(d[i][j]==1)
        {
            afisare(i-1,j-1);
            fout<<a[i]<<' ';
        }
        else if(d[i][j]==2)
        {
            afisare(i,j-1);
        }
        else
        {
            afisare(i-1,j);
        }
    }
}
int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                lg[i][j]=lg[i-1][j-1]+1;
                d[i][j]=1;
            }
            else
            {
                if(lg[i-1][j]<lg[i][j-1])
                {
                    lg[i][j]=lg[i][j-1];
                    d[i][j]=2;
                }
                else
                {
                    lg[i][j]=lg[i-1][j];
                    d[i][j]=3;
                }
            }
    fout<<lg[n][m]<<'\n';
    afisare(n,m);
}
