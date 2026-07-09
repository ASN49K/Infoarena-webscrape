#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmslc.out");

int mat[1026][1026],v[1026],x[1026],i,n,j,m,rec[1026],cont=0;
int main()
{
    f>>m>>n;
    for (i=1; i<=m; i++) f>>v[i];
    for (i=1; i<=n; i++) f>>x[i];


    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        if (v[i]==x[j])
        mat[i][j]=mat[i-1][j-1]+1;
    else
        mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

   i=m; j=n;

   while (i && j)
   if (v[i]==x[j])
   {
       rec[++cont]=v[i];
       i--;
       j--;
   }
   else
    if (mat[i-1][j]>mat[i][j-1])
    i--;
   else
    j--;
   g<<cont<<'\n';
   for (i=cont; i>=1; i--) g<<rec[i]<<" ";
    return 0;
}
