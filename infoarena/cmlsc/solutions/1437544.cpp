#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int n, m, i, j, nr=0;
    f>>n>>m;
    int v[n+1], b[n+1];
    for(i=1; i<=n; i++)
        f>>v[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            if(v[i]==b[j])
        {
            nr++;
            b[nr]=v[i];
        }
    }
    g<<nr<<"\n";
    for(i=1; i<=nr; i++)
        g<<b[i]<<" ";
    return 0;
}
