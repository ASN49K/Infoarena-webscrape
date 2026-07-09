#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1050][1050],i,j,n,m,x[1050],y[1050];
void cc(int i,int j,int k)
{
    if(k<=a[n][m])
    {
    if(x[i]==y[j])
    {
         if(x[i-1]==y[j-1])
              cc(i-1,j-1,k+1);
        else
            if(a[i-1][j]==a[i][j])
            cc(i-1,j,k+1);
        else
            cc(i,j-1,k+1);
        g<<x[i]<<" ";
    }
    else
        if(x[i-1]==y[j-1])
              cc(i-1,j-1,k);
        else
            if(a[i-1][j]==a[i][j])
            cc(i-1,j,k);
        else
            cc(i,j-1,k);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(x[i]==y[j])
            a[i][j]=a[i-1][j-1]+1;
        else
            a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    g<<a[n][m]<<'\n';
    cc(n,m,1);
    return 0;
}
