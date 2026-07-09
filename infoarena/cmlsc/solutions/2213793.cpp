#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,i,j,v[1030],k,a[1030],b[1030];
int c[1030][1030];
int main()
{
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(i=1;i<=n;i++)
        in>>b[i];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    i=m;
    j=n;
    while(i>0)
    {
        if(c[i][j]==c[i-1][j-1]+1)
        {
            v[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j]<c[i][j-1]) j--;
            else i--;
        }
    }
    out<<k<<'\n';
    for(i=k;i>0;i--)
        out<<v[i]<<" ";
    return 0;
}
