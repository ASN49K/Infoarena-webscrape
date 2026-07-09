#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n,m, a[1024],b[1024],d[1024][1024],sir[1024],best;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
   f>>m>>n;
   for(int i=1;i<=m;i++)
    f>>a[i];

   for(int i=1;i<=n;i++)
      f>>b[i];

   for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
       if (a[i] == b[j]) d[i][j] = 1 + d[i-1][j-1];
       else d[i][j] = max(d[i-1][j], d[i][j-1]);
    int i,j;
    for(i=m,j=n;i;)
    {
        if (a[i] == b[j])
            sir[++best] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1]) --j;
          else --i;
    }

    g<<best<<'\n';
    for(int i=best; i>0;i--)
        g<<sir[i]<<" ";

   f.close();
   g.close();
}
