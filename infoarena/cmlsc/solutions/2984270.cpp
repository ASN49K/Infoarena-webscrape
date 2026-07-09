#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int cst=1030;
int mat[cst][cst],v1[cst],v2[cst],r[cst];
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v1[i];
    for(int i=1; i<=m; i++)
        fin>>v2[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v1[i]==v2[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    fout<<mat[n][m]<<'\n';
    int cn=n,cm=m,cnt=mat[n][m];
    while(cn>0&&cm>0)
    {
        if(v1[cn]==v2[cm])
        {
            r[cnt]= v1[cn];
            cnt--;
            cn--;
            cm--;
        }
        else if(mat[cn-1][cm]>mat[cn][cm-1])
            cn--;
        else cm--;
    }
    for(int i=1; i<=mat[n][m]; i++)
        fout<<r[i]<<" ";
    return 0;
}
