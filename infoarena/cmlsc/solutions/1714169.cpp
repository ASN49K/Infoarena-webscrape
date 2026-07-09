#include <iostream>
#define NMax 1024
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, a[NMax], b[NMax], d[NMax][NMax], sir[NMax], bst,i, j;
int main()
{

    f>>n>>m;
    for(i=1; i<=n; i++)f>>a[i];
    for(i=1; i<=m; i++)f>>b[i];

    for(i=1; i<=n; i++)
         for(j=1; j<=m; j++)
            if (a[i] == b[j])d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = max(d[i-1][j], d[i][j-1]);

    for(i=n; i>0; i--)
     for(j=m; j>0; j--)
        if (a[i] == b[j])
            sir[++bst] = a[i], i--, j--;
        else if (d[i-1][j] < d[i][j-1])j--;
        else i--;

    g<<bst<<"\n";
    for(i = bst; i>=1; --i)g<<sir[i]<<" ";
    return 0;
}
