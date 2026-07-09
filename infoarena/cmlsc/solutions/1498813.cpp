#include <fstream>
#include <cmath>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,v[1024],ma[1024],p,k,q,maxx,D[1024][1024],sir[1024],bst;

int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>v[i];
    for(int i=1;i<=m;i++)
        in>>ma[i];
  for(int i=1;i<=m;i++)
        for (int j=1; j<=n;j++)
            if (v[i] == ma[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);

    int j;
    for (int i = n, j = m; i;)
        if (v[i] == ma[j])
            sir[++bst] = v[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    out<<bst<<'\n';
    for(int i=bst;i>=1;--i)
        out<<sir[i]<<" ";
    return 0;
}
