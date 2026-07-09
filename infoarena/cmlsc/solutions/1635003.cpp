#include <fstream>
#include <iostream>
using namespace std;
int n,m,x,i,j,a[1030],b[1030],c[1030][1030],d[1030];
int constrmat(int a[1030],int b[1030],int c[1030][1030])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    return c[n][m];
}
int parcour( int c[1030][1030])
{
    int i=n;
    int j=m;
    int nrlen=0;
    while(nrlen<=c[n][m] && i>=1 && j>=1)
    {
        if(a[i]==b[j])
            d[x--]=a[i],i-=1,j-=1,nrlen++;
        else if(a[i]!=b[j] && c[i-1][j]==c[i][j-1])
        {
            i-=1;
        }
        else if(a[i]!=b[j] && c[i-1][j]!=c[i][j-1])
        {
            if(c[i-1][j]>c[i][j-1])
                i-=1;
            else j-=1;
        }
    }
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;
    for(i=1;i<=n;i++)
       f >> a[i];
    for(i=1;i<=m;i++)
       f >> b[i];
    x=constrmat(a,b,c);
   g << x << endl;
    parcour(c);
    for(i=1;i<=c[n][m];i++)
       g << d[i] << " ";
    return 0;
}
