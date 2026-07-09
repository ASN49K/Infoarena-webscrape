#include <fstream>
#include <algorithm>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int a[100001],b[100001],c[110][110],i,j,n,m,d[100001];
int main()
{
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>a[i];
    for(j=1; j<=m; j++)
        in>>b[j];

        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            c[i][j]=0;

    for(j=1; j<=m; j++)
        {
            for(i=j; i<=m; i++)
            {
                if(a[1]==b[j]) c[1][j]=1;
            }
        }

    for(i=1; i<=n; i++)
        {
            for(j=i; j<=n; j++)
            {
                if(b[1]==a[i]) c[i][1]=1;
            }
        }

    for(i=2; i<=n; i++)
    {
        for(j=2; j<=m; j++)
        {
            if(a[i]==b[j]) {c[i][j]=c[i-1][j-1]+1; }
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    out<<c[n][m]<<endl;
    i=n; j=m; int k=0;
    while(i>0 && j>0)
    {
        if(a[i]==b[j]) {d[++k]=a[i]; i--; j--;}
        else {if(c[i-1][j]>c[i][j-1]) i--;
            else j--;}

    }
    for(i=k; i>=1; i--)
        out<<d[i]<<" ";
    return 0;
}
