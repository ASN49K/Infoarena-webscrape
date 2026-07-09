#include <iostream>
#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;
int m,n,i,j,a[256],b[256],d[256][256], sir[256], bst=0;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)f>>a[i];
    for(i=1;i<=n;i++)f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])d[i][j]= 1 + d[i-1][j-1];
                else d[i][j] = maxim(d[i-1][j], d[i][j-1]);

     for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
      g<<bst<<'\n';
      for(;bst;bst--){
        g<<sir[bst]<<' ';
      }
    return 0;

}
