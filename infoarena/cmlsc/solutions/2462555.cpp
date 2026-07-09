#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int nx = 1025;
deque < short > s;
int n,m,mat[nx][nx],v[nx],w[nx],nr;

int main()
{
    in>>n>>m;
    for(int i = 1; i<=n; i++)
        in>>v[i];
    for(int i = 1; i<=m; i++)
        in>>w[i];
    for(int i = 1; i<=n; i++)
        for( int j = 1; j<=m; j++)
            if(v[i]==w[j]) mat[i][j] = mat[i-1][j-1] + 1;
            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
    nr = mat[n][m];
    int i = n;
    int j = m;
    while(i && j && mat[i][j])
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
    out<<nr<<'\n';
    for(deque < short > :: iterator it = s.begin(); it!=s.end(); it++)
        out<<*it<<' ';
    return 0;
}
