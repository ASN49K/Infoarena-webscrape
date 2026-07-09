#include <fstream>
using namespace std;
int s[1025][1025],a[1025],b[1025],v[1025];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,i,j,maxx;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        f>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                s[i][j]=s[i-1][j-1]+1;
            }
            else
            {
                s[i][j]=max(s[i][j-1],s[i-1][j]);
            }
        }
    }
    g<<s[n][m]<<endl;
    i=n; j=m;
    maxx=s[n][m];
    while(s[i][j]>0)
    {
        if(a[i]==b[j])
        {
            v[maxx]=a[i];
            i--; j--;
            maxx--;
        }
        else if(s[i][j-1]>s[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    for(i=1;i<=s[n][m];i++)
    {
        g<<v[i]<<' ';
    }
}
