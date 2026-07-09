#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int nx=1025;
int mat[nx][nx],v[nx],w[nx];
int n,m;
int main()
{
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>v[i];
    for(int i=1; i<=m; i++)
        in>>w[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v[i]==w[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    deque < int > sol;
    out<<mat[n][m]<<'\n';
    int i=n,j=m;
    while(i)
    {
        if(v[i]==w[j])
        {
            sol.push_front(v[i]);
            i--;
            j--;
        }
        else
        {
            if(mat[i-1][j]>mat[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(deque < int > :: iterator it=sol.begin();it!=sol.end();it++)
        out<<*it<<' ';
    return 0;
}
