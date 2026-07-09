#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int d[1026][1026];
int n,m,x;
int a[1026],b[1026];
int sol[1026];

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    fout<<d[n][m]<<"\n";
    int j=m;
    int i=n;
    for(; i>0 && j>0; )
    {
        if(a[i]==b[j])
        {
            sol[x++]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]>d[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    for(i=x-1; i>=0; i--)
    {
        fout<<sol[i]<<" ";
    }
    return 0;
}
