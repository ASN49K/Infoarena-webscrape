#include <fstream>
#define NMAX 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int a[NMAX],b[NMAX];
int sol[NMAX][NMAX];
int c[NMAX],k;

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])
                sol[i][j]=1+sol[i-1][j-1];
            else
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
    //g<<sol[n][m]<<'\n';
    int i=n;
    int j=m;
    while(!(i==0 or j==0))
    {
        if(a[i]==b[j])
        {
           c[++k]=a[i];
            i--;
            j--;
        }
        else
            if(sol[i][j]==sol[i-1][j])
                i--;
            else
                j--;
    }
    g<<k<<'\n';
    for(int i=k;i>=1;i--)
        g<<c[i]<<" ";
    f.close();
    g.close();
    return 0;
}
