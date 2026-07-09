#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N=1025;
int m,n, a[N], b[N], c[N][N], x[N];

int main()
{
    int i,j,t;
    f>>m>>n;
    for (i=1; i<=m; i++)
        f>>a[i];
    for (i=1; i<=n; i++)
        f>>b[i];
    c[0][0]=0;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    i=m;
    j=n;
    t=0;
    while(i>0&&j>0)
        if(a[i]==b[j])
        {
            x[++t]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j]<c[i][j-1])
            j--;
        else i--;
    g<<t<<"\n";
    for(i=t; i>=1; i--)
        g<<x[i]<<" ";

}
