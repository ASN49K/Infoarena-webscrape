#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m;
const int nx = 1025;
int v[nx],w[nx],mat[nx][nx];
deque < int > s;
int main()
{
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>v[i];
    for(int j=1; j<=m; j++ )
        in>>w[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i]==w[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    out<<mat[n][m]<<'\n';
    int i=n;
    int j=m;
    while(i && j)
    {
        if(v[i]==w[j])
        {
            s.push_front(v[i]);
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
    for(deque < int > :: iterator it = s.begin(); it!=s.end(); it++)
        out<<*it<<' ';
    return 0;
}
