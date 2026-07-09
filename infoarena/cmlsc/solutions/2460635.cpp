#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long long v[1030],a[1030],mat[1025][1025];
vector<int>rez;
int main()
{
    long long n,m;
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>v[i];
    for(int j=1; j<=m; j++)
        f>>a[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i]==a[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    g<<mat[n][m]<<'\n';
    int i=n,j=m,p=mat[n][m];
    while(p)
        if(v[i]==a[j]&&p==mat[i][j])
            rez.push_back(v[i]),i--,j--,p--;
        else
        {
            if(mat[i-1][j]>mat[i][j-1])
                i--;
            else j--;
        }
    for(int i=rez.size()-1;i>=0;i--)
        g<<rez.at(i)<<" ";
    return 0;
}
