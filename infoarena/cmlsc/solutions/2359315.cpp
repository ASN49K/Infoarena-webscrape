#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],sol[1024],pd[1024][1024],k;

int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                pd[i][j]=pd[i-1][j-1]+1;
            }
            else
            {
                pd[i][j]=max(pd[i-1][j],pd[i][j-1]);
            }
        }
    }
    i=n; j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--; j--;
        }
        else if(pd[i-1][j]>pd[i][j-1]) i--;
        else j--;
    }
    fout<<k<<"\n";
    for(i=k;i>=1;fout<<sol[i--]<<" ");
    return 0;
}
