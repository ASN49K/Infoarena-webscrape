#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k;
int a[1030],b[1030];
int LCS[1030][1030];
int sol[1030];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) f>>a[i];
    for(i=1;i<=m;++i) f>>b[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(a[i]==b[j]) LCS[i][j]=LCS[i-1][j-1]+1;
            else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    k=0;
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j]) ++k,sol[k]=a[i],--i,--j;
        else
        {
            if(LCS[i-1][j]<LCS[i][j-1]) --j;
            else --i;
        }
    }
    g<<k<<'\n';
    for(i=k;i>=1;--i) g<<sol[i]<<" ";
    g<<'\n';
    return 0;
}
