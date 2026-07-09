#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define nmax 1026
int a[nmax],b[nmax],c[nmax][nmax];
void reconstituie(int i,int j)
{
    if(i>0 and j>0)
    {
        if(a[i]==b[j])
        {
            reconstituie(i-1,j-1);
            g<<a[i]<<" ";
        }
        else
            if(c[i][j-1]>c[i-1][j])
                reconstituie(i,j-1);
            else
                reconstituie(i-1,j);
    }
}
int main()
{
    int n,m,i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    g<<c[n][m]<<'\n';
    reconstituie(n,m);
    return 0;
}
