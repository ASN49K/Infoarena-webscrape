//#pragma GCC optimize("O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int mat[1035][1035], v[1035], v2[1035], rez[1035];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m, poz=1;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>v[i];
    for(int i=1; i<=m; i++)
        cin>>v2[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v[i]==v2[j])
                mat[i][j]=mat[i-1][j-1]+1;

            mat[i][j]=max(mat[i][j], max(mat[i][j-1], mat[i-1][j]));
        }
    }
    cout<<mat[n][m]<<'\n';
    int x=n, y=m;
    while(x>0 && y>0)
    {
        if(mat[x][y]==mat[x-1][y])
            x--;
        else if(mat[x][y]==mat[x][y-1])
            y--;
        else
        {
            rez[poz++]=v[x];
            x--;
            y--;
        }
    }
    for(int i=poz-1; i>0; i--)
        cout<<rez[i]<<" ";
    return 0;
}
