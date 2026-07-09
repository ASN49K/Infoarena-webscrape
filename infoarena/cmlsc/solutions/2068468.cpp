#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025],b[1025],n,m;
string v[1025][1025];

void read()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int i=1;i<=m;++i)
        f>>b[i];

}

int main()
{
    read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
            {
                v[i][j]=v[i-1][j-1];
                v[i][j].push_back(a[i]);
            }
            else
            if(v[i][j-1].size()>=v[i-1][j].size())
                v[i][j]=v[i][j-1];
            else
                v[i][j]=v[i-1][j];
        }
    g<<v[n][m].size()<<"\n";
    for(auto i:v[n][m])
        g<<int(i)<<" ";
    return 0;
}
