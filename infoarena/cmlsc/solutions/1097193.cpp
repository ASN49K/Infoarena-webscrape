#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,nr,v[1050],w[1050],fin[1050],aux;
int main()
{
    f>>n>>m;
    for (int i=1; i<=n; ++i) f>>v[i];
    for (int i=1; i<=m; ++i) f>>w[i];
    for (int i=1; i<=n; ++i)
       for (int j=1; j<=m; ++j)
          if (v[i]==w[j])
             {
                 ++nr;
                 ++aux;
                 fin[aux]=v[i];
             }
    g<<nr<<'\n';
    for (int i=1; i<=aux; ++i) g<<fin[i]<<' ';
    g<<'\n';
    f.close(); g.close();
    return 0;
}
