#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1001][1001],b[1001],c[1001],s[1001];
int main()
{
    int n,m,i,j,x=0;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>b[i];
        for(j=1;j<=m;j++)
        f>>c[j];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if(b[i]==c[j])
                a[i][j]=a[i-1][j-1]+1;
    else
        a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
            i=n;
            j=m;
    while(a[i][j])
    {
        while(a[i][j]==a[i-1][j])
            i--;
        while(a[i][j]==a[i][j-1])
            j--;
        x++;
        s[x]=b[i];
    }
    g<<a[n][m]<<endl;
    for(i=1;i<=x;i++)
        g<<s[i]<<" ";
   return 0;
}
