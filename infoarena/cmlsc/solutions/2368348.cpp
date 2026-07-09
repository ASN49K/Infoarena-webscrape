#include <bits/stdc++.h>
#define N 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[N],b[N],n,m,c[N][N],sol[N],sl;

int det_lcs()
{
    int i,j;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    return c[n][m];
}

void back_lcs(int i,int j)
{
    if(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            sl++;
            sol[sl]=a[i];
            back_lcs(i-1,j-1);
        }
        else
            if(c[i-1][j]>c[i][j-1])
                back_lcs(i-1,j);
            else
                back_lcs(j-1,i);
    }
}

int main()
{
    int i;
    fin>>n>>m;

    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    fout<<det_lcs()<<"\n";

    back_lcs(n,m);

    for(i=sl;i>=1;i--)
        fout<<sol[i]<<" ";
    return 0;
}
