#include <iostream>
#include <fstream>
#define NM 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NM], b[NM], n, m, lg[NM][NM];///, d[NM][NM];

void scrie(int i, int j);

int main()
{
    int i, j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                lg[i][j]=1+lg[i-1][j-1];
               /// d[i][j]=1;
            }
            else if(lg[i-1][j]>lg[i][j-1])
            {
                lg[i][j]=lg[i-1][j];
                ///d[i][j]=2;
            }
            else
            {
                lg[i][j]=lg[i][j-1];
               /// d[i][j]=3;
            }
        }
    }
    fout<<lg[n][m]<<'\n';
    scrie(n,m);
}

void scrie(int i, int j)
{
    if(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            scrie(i-1, j-1);
            fout<<a[i]<<" ";
        }
        else if(lg[i-1][j]>lg[i][j-1])
            scrie(i-1, j);
        else
            scrie(i, j-1);
    }
}
