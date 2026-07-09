#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
const int NMAX=1025;
int a[NMAX],b[NMAX],d[NMAX][NMAX],kon,copie[NMAX];
int main()
{
    int n,m,i,j;              /// 1 7 3 9 8
    fin>>n>>m;          /// 2 7 6 8 9          vector: 9
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            if(d[i-1][j]>d[i][j])
                d[i][j]=d[i-1][j];
             if(d[i][j-1]>d[i][j])
                d[i][j]=d[i][j-1];
        }
    fout <<d[n][m]<<"\n";
    i=n,j=m;
    while(i>0 && j>0)
    {
        if(d[i-1][j]==d[i][j])
            i--;
        else
        {
            if(d[i][j-1]==d[i][j])
                j--;
            else
            {
                copie[++kon]=a[i];
                i--;
                j--;
            }
        }
    }
    for(i=kon;i>=1;i--)
        fout<<copie[i]<<" ";
    return 0;
}
