
#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v[1025][1025], s[1025];

int main()
{
    fin>>n>>m;
    for(int i=2; i<=n+1; i++)
    {
        fin>>v[i][0];
    }
    for(int i=2; i<=m+1; i++)
    {
        fin>>v[0][i];
    }
    for(int i=2; i<=n+1; i++)
    {
        for(int j=2; j<=m+1; j++)
        {
            if(v[i][0]==v[0][j])
            {
                v[i][j]=v[i-1][j-1]+1;
                s[v[i][j]]=v[i][0];
            }
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    fout<<v[n+1][m+1]<<endl;
    for(int i=1; i<=v[n+1][m+1]; i++)
    {
        fout<<s[i]<<" ";
    }
    

    return 0;
}