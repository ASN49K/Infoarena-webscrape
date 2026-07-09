#include <fstream>
using namespace std;

short m,n, a[1025], b[1025], c[1025][1025],d[1025];

int main()
{   ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int i,k,j;
    f>>m>>n;
    for (i=1;i<=m;i++)
    f>>a[i];
    for (i=1;i<=n;i++)
    f>>b[i];
    c[0][0]=0;
    for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
    if (a[i]==b[j])
    c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);
    k=0; i=m; j=n;
    while(i>0 && j>0)
    {  if(a[i]==b[j])
        {   d[++k]=a[i];
            i--;
            j--;
        }
        else
        {   if(c[i-1][j]<c[i][j-1])
            j--;
            else
            i--;
        }
    }
   for(i=k;i>=1;i--)
   g<<d[i]<<" ";


}
