#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1030],b[1030],mt[1030][1030],v[1030],nr;

int main()
{
    fin >> n >> m;
    for(i=1;i<=n;i++)
        fin >> a[i];
    for(j=1;j<=m;j++)
        fin >> b[j];
    if(a[1]==b[1])
        mt[1][1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
               mt[i][j]=mt[i-1][j-1]+1;
            else
                mt[i][j]=max(mt[i-1][j],mt[i][j-1]);
        }
    }
    fout << mt[n][m] << '\n';
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            v[++nr]=a[i];
            i--,j--;
        }
       else
        if(mt[i-1][j]>mt[i][j-1])
                i--;
        else j--;

    }
    for(i=nr;i>=1;i--)
        fout << v[i] << ' ';

    return 0;
}
