#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v[1025],f[1025],c[1025][1025],i,j,d[1025],nr;
int cmmdc(int a,int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{
    fin>>n>>m;
    for( i=1; i<=n; i++)
        {fin>>v[i];c[0][i]=0;}
    for( i=1; i<=m; i++)
        {fin>>f[i];c[i][0]=0;}
    for( i=1; i<=n; i++)
        for( j=1; j<=m; j++)
    {
        if(v[i]==f[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
    fout<<c[n][m]<<'\n';
    i=n; j=m; nr=c[n][m];
    while(nr)
    {
        if(c[i][j-1]!=c[i][j] && c[i-1][j]!=c[i][j] && c[i-1][j-1]!=c[i][j])
            {d[nr--]=v[i]; i--; j--;}
            else if(c[i-1][j]==max(c[i-1][j],c[i][j-1])) i--;
                    else j--;
    }
    for(i=1; i<=c[n][m]; i++)
        fout<<d[i]<<' ';
    return 0;
}
