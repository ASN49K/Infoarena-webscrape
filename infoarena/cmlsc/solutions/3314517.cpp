//#pragma GCC optimize("O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int mat[1025][1025], v[1025], v2[1025];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m;
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
                mat[i][j]=max(mat[i][j-1], mat[i-1][j])+1;
            else
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);
        }
    }
    cout<<mat[n][m]<<'\n';
    for(int i=1; i<=m; i++)
    {
        if(mat[n][i]==mat[n][i-1]+1)
            cout<<v2[i]<<" ";
    }
    return 0;
}

