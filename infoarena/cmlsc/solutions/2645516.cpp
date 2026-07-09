#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short n,m,i,j,t[1025][1025],a[1025],b[1025],best,ans[1025],k;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)f>>a[i];
    for(i=1;i<=n;i++)f>>b[i];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])t[i][j]=t[i-1][j-1]+1;
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }

            best=max(best,t[i][j]);
        }
    }
    g<<best<<'\n';
    i=m;j=n;
    while(i)
    {
        if(a[i]==b[j])ans[++k]=a[i],i--,j--;
        else if(t[i][j-1]>t[i-1][j])j--;
        else
            i--;
    }
    for(i=k;i>=1;i--)g<<ans[i]<<" ";
    return 0;
}
