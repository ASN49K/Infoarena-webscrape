#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int lim=1025;
int v[lim],f[lim],sol[lim];
int dp[lim][lim];
int last[lim][lim];
int n,m,cx,cy,aux,nr;
int main()
{
    ios_base::sync_with_stdio(false);
    in.tie(0),out.tie(0);
    in>>n>>m;
    for(int i=1;i<=n;++i)
        in>>v[i];
    for(int j=1;j<=m;++j)
        in>>f[j];
    for(int i=1;i<=n;++i)
    {
        nr=0;
        for(int j=1;j<=m;++j)
        {
            if(dp[i-1][j]>=dp[i][j-1])
                last[i][j]=(i-1)*(m+1)+j,nr=0;
            else last[i][j]=i*(m+1)+(j-1),nr++;
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(v[i]==f[j])
            if((nr>0 and v[i]!=f[j-nr]) or (nr==0))
                dp[i][j]++;
        }
    }
    out<<dp[n][m]<<'\n';
    cx=n;
    cy=m;
    while(dp[cx][cy])
    {
        while(v[cx]!=f[cy])
        {
            aux=last[cx][cy];
            cx=aux/(m+1);
            cy=aux%(m+1);
        }
        sol[dp[cx][cy]]=v[cx];
        aux=last[cx][cy];
        cx=aux/(m+1);
        cy=aux%(m+1);
    }
    for(int i=1;i<=dp[n][m];++i)
        out<<sol[i]<<" ";
    return 0;
}
