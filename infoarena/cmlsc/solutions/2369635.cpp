#include <bits/stdc++.h>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
const int nmax=12e2+3;
int n1,n2,v1[nmax],v2[nmax],d[nmax][nmax],t1,t2;
vector <int> sol;
int main()
{
    ios::sync_with_stdio(false);
    f>>n1>>n2;
    for(int i=1;i<=n1;++i) f>>v1[i];
    for(int i=1;i<=n2;++i) f>>v2[i];
    for(int i=1;i<=n1;++i)
    {
        for(int j=1;j<=n2;++j)
        {
            if(v1[i]==v2[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    }
    g<<d[n1][n2]<<'\n';
    t1=n1;
    t2=n2;
    while(t1&&t2)
    {
        if(v1[t1]==v2[t2])
        {
            sol.push_back(v1[t1]);
            --t1;
            --t2;
            continue;
        }
        if(d[t1][t2-1]<=d[t1-1][t2]) --t1;
        else --t2;
    }
    reverse(sol.begin(),sol.end());
    for(int i=0;i<sol.size();++i) g<<sol[i]<<' ';
    return 0;
}
