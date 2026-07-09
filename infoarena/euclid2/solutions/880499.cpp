 #include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long n,m,re,i,prim,d;
int main()
{
    f>>n;

     m=sqrtf(n);
  int v[n+1];
  for (i=2;i<=n;i++) v[i]=0;
  int x[m+1];
  for (i=2;i<=m;i++)
  {prim=1;
  for (d=2; d<=sqrtf(i) && prim ;d++) { if (i%d==0) prim=0;}
        if (prim) {g << i << " ";}
  }
  for (i=2;i<=m;i++) {re=0; while (re<n) {re=re+i; v[re]=1;}}
  for (i=1;i<=n;i++)  { if (!v[i]) g << i << " ";}
f.close();
g.close();
    return 0;
}
