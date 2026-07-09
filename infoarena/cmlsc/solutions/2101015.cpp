#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int nx=1026;
int n,m,v[nx],w[nx],i,j;
int mat[nx][nx];
deque < int > sol;
int main()
{
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>v[i];
    for(i=1; i<=m; i++)
        in>>w[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(v[i]==w[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    i=n;
    j=m;
    while(i && j)
    {
        if(v[i]==w[j])
        {
            sol.push_front(v[i]);
            i--;
            j--;
        }
        else
        {
            if(mat[i][j-1]>mat[i-1][j]) j--;
            else i--;

        }
    }
    out<<sol.size()<<'\n';
    for(deque < int > :: iterator it=sol.begin(); it!=sol.end(); it++)
        out<<*it<<' ';
    return 0;
}
