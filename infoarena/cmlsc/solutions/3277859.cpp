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

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=0;i<=n;i++) mat[0][i]=0;
    for(int i=0;i<=m;i++) mat[i][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v[j]==a[i]) mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }
    cout<<mat[m][n];
    return 0;
}
