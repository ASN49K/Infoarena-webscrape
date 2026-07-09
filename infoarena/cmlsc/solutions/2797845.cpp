#include <bits/stdc++.h>
#define nmax 1050

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[nmax],b[nmax],n,m,best[nmax][nmax],sir[nmax];

void read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
}

void dp()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
            {
                best[i][j]=best[i-1][j-1]+1;
            }
            else
                best[i][j]=max(best[i-1][j],best[i][j-1]);
}

void solve()
{
    dp();
    fout<<best[n][m]<<"\n";
    int i=n,j=m,l=1;
    while(best[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            sir[l++]=a[i];
            i--;
            j--;
        }
        else if (a[i-1]>b[j-1])
            i--;
        else
            j--;
    }
    for(int i=l-1;i>=1;i--)
        fout<<sir[i]<<" ";
}

int main()
{
    read();
    solve();
    return 0;
}
