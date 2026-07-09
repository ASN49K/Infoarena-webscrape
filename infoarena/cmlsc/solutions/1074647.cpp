#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1050],b[1050],dp[1050][1050],maxim,maximi,maximj,v[1050];

inline void Citire()
{
    int i;
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>a[i];
    for (i=1;i<=m;i++)
        fin>>b[i];
}

void Rezolva()
{
   int i,j;
   for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
               dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

}

inline void Afisare()
{
    int i,j,vlen,vlenlen;
    vlen=dp[n][m];
    vlenlen=vlen;
    fout<<vlen<<"\n";
    i=n;j=m;
    while (dp[i][j]!=0)
        {
            if (a[i]==b[j])
                {
                    v[vlen]=a[i];
                    vlen--;
                    i--;j--;
                }
            else if (dp[i-1][j]==vlen)
                    i--;
            else j--;
        }
    for (i=1;i<=vlenlen;i++)
        fout<<v[i]<<" ";
    fout<<"\n";
}

int main()
{
    Citire();
    Rezolva();
    Afisare();
    return 0;
}
