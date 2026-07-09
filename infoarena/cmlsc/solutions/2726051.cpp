#include <bits/stdc++.h>
#define lim 1025

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, vn[lim], vm[lim], mat[lim][lim];
stack <int> s;

void read()
{
    in>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        in>>vn[i];
    }
    for(int i=1; i<=m; ++i)
    {
        in>>vm[i];
    }
}

void solve()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(vn[i]==vm[j])
            {
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
            {
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);
            }
        }
    }
    /*for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<'\n';
    }*/
}

void track_back()
{
    int i=n, j=m;
    while(i>=1 && j>=1)
    {
        if(vn[i]==vm[j])
        {
            s.push(vn[i]);
            i--;
            j--;
        }
        else
        {
            if(mat[i][j]==mat[i-1][j])
                i--;
            else if(mat[i][j]==mat[i][j-1])
                j--;
        }
    }
}

int main()
{
    read();
    solve();
    out<<mat[n][m]<<'\n';
    track_back();
    while(!s.empty())
    {
        out<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
