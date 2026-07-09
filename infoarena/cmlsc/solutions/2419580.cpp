#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v[1030],f[1030],n,m,c[1030][1030],maxx,re[1030],l;
int lcm(int n, int m, int v[1030],int f[1030])
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i]==f[j])
                c[i][j]=c[i-1][j-1]+1,re[++l]=v[i];
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
    return c[n][m];
}
void citire()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>v[i];
    for(int i=1; i<=m; i++)
        cin>>f[i];
}
void printare()
{
    cout<<lcm(n,m,v,f)<<'\n';
    for(int i=1;i<=l;i++)
        cout<<re[i]<<' ';
   /* for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(j==1)
                if(c[i][j]>c[i-1][n])
                    cout<<v[i]<<' ';*/
}
int main()
{
    citire();
    printare();
    return 0;
}
