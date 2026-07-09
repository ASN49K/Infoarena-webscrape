#include <fstream>
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int m,n,i,v1[1030],v2[1030],j,d[1030][1030],k,rez[1030];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>v1[i];
    for(i=1;i<=n;i++)
        f>>v2[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
        if(v1[i]==v2[j])
            d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=MAX(d[i-1][j],d[i][j-1]);
        }
    for(i=m,j=n;i;)
        {
        if(v1[i]==v2[j])
        {
            rez[++k]=v1[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
        }
    g<<d[m][n]<<"\n";
    for(i=k;i>=1;i--)
        g<<rez[i]<<" ";
}

