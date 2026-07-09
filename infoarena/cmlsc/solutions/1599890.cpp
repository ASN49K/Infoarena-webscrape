#include <iostream>
#include <fstream>
using namespace std;
int v[1028][1028];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    unsigned n,m,s=0;
    f>>m>>n;
    for(int i=1;i<=m;++i)
    {
        f>>v[0][i];
    }
    for(int i=1;i<=n;++i)
    {
        f>>v[i][0];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(v[0][j]==v[i][0]) {v[i][j]=1; s++; break;}
        }
    }
    g<<s<<"\n";
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(v[i][j]==1) {g<<v[i][0]<<" "; break;}
        }
    }
    return 0;
}
