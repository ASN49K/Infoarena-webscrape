#include <bits/stdc++.h>
using namespace std;

#define ll long long

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
/*
*/
#define cin fin
#define cout fout



const int MAXN=1300;
int n, m;
int v1[MAXN], v2[MAXN];
int v[MAXN][MAXN];
deque<int>out;

void read()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>v1[i];
    for(int i=1; i<=m; i++)
        cin>>v2[i];
}


void solve()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v1[i]==v2[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
    cout<<v[n][m]<<"\n";
    int i=n, j=m;
    while(i&&j)
    {
        if(v1[i]==v2[j])
        {
            out.push_front(v1[i]);
            i--,j--;
        }
        else
        if(v[i][j]==v[i-1][j])
            i--;
        else
            j--;
    }
    for(auto el:out)
        cout<<el<<" ";
}

int main()
{
    read();
    solve();

    return 0;
}
