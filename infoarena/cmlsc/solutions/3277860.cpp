#include <iostream>
#include <fstream>
#include <vector>
#define INF 1000000000
#include <queue>

using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int mat[1030][1030];
int v[1030],a[1030];
int afis[20000];
int main()
{
    int n,m;
    in>>n>>m;
    for(int i=1; i<=n; i++) in>>v[i];
    for(int i=1; i<=m; i++) in>>a[i];
    for(int i=0; i<=n; i++) mat[0][i]=0;
    for(int i=0; i<=m; i++) mat[i][0]=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(v[j]==a[i]) mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }
    int k=0;
    while(m>0 || n>0)
    {
        if(mat[m][n]>mat[m-1][n] && mat[m][n]>mat[m][n-1])
        {
            k++;
            afis[k]=v[n];
            m--;
            n--;
        }
        else
        {
            if(mat[m][n]==mat[m-1][n]) m--;
            else
                n--;
        }

    }
    out<<k<<'\n';
    for(int i=k;i>=1;i--) out<<afis[i]<<' ';
    return 0;
}
