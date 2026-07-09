#include<bits/stdc++.h>
using namespace std;

int n,m,i,j;
int a[1030],b[1030],s[1030][1030];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
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
                s[i][j]=s[i-1][j-1]+1;
            else
                s[i][j]=max(s[i-1][j],s[i][j-1]);
        }
    }

    fout<<s[n][m]<<"\n";

    for(i=1;i<=n;i++)
        if(s[i][m]==s[i-1][m]+1)
            fout<<a[i]<<" ";

    fout.close();
    fout.close();
    return 0;
}
