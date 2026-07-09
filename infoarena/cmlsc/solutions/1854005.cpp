#include <fstream>
#define FOR(i, a, b) for (i = a; i <= b; ++i)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int l1, l2, a[10001], b[10001], d[1001][1001], sir[10001],bst;

int main()
{ int i, j;
  f>>l1>>l2;
  for(i=1;i<=l1;i++)
    f>>a[i];
  for(i=1;i<=l2;i++)
    f>>b[i];
  for(i=1;i<=l1;i++)
     for(j=1;j<=l2;j++)
      if(a[i]==b[j])
        d[i][j]=1+d[i-1][j-1];
      else
       d[i][j]=max(d[i-1][j],d[i][j-1]);

            for (i = l1, j = l2; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
        g<<bst<<'\n';
        for(i=bst;i;--i)
            g<<sir[i]<<' ';
}
