#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,lun,a[1030],b[1030],sir[1030],x[1030][1030];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                x[i][j]=1+x[i-1][j-1];
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);

    i=n;
    j=m;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            sir[++lun]=a[i];
            i--;
            j--;
        }
        else if(x[i-1][j]<x[i][j-1])
            j--;
        else
            i--;
    }
    fout<<lun<<'\n';
    for(i=lun;i>=1;i--)
        fout<<sir[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
