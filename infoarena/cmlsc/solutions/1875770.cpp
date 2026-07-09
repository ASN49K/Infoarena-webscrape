#include <bits/stdc++.h>
#define nm 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[nm],b[nm],d[nm][nm],rez[nm],nr;

int main()
{
    int i,j;
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
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }

    for(i=n,j=m;i>0;)
    {
        if(a[i]==b[j])
            {
                rez[++nr]=a[i];
                i--;j--;
            }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    }

    fout<<nr<<'\n';
    for(i=nr;i>0;i--)
        fout<<rez[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
