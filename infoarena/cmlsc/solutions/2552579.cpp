#include <fstream>
#define maxi(a, b) ((a > b) ? a : b)
#define NMAX 1028
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[NMAX],b[NMAX],c[NMAX][NMAX],v[NMAX];
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>a[i];
    for(int i=1;i<=n;i++)
        f>>b[i];
    for(int i=0;i<m;i++)
        c[i][0]=0;
    for(int j=0;j<n;j++)
        c[0][j]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
        else
            c[i][j]=maxi(c[i-1][j], c[i][j-1]);
    }
    g<<c[m][n]<<'\n';
    int ct=0;
    for(int i=m,j=n;i;)
    {
        if(a[i]==b[j])
        {
            v[++ct]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j]>c[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=ct;i>=1;i--)
        g<<v[i]<<" ";
    return 0;
}
